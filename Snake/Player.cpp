#include "Player.h"

Player::Player(SnakeBody* snake)
{
	this->snake = snake;
}

Player::~Player()
{
	graph.join();
	delete snake;
	delete window;
	delete cir;
}

SnakeBody* Player::Snake()
{
	return snake;
}

IPlayer::Move Player::GetMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return IPlayer::Move::Left;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return IPlayer::Move::Right;
	return IPlayer::Move::None;
}

void Player::SetGameField(IConstGame* game)
{
	this->game = game;
	CreateWindow();
}

void Player::DrawFrame()
{
	if (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window->close();
				game->Stop();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) game->Stop();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Pause && !isPausePressed) {
				game->PlayPause();
				isPausePressed = true;
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Pause) isPausePressed = false;
			else if (event.type == sf::Event::Resized) {
				if (PrevWidth == event.size.width)
					window->setSize(sf::Vector2u(PrevWidth = PrevHeight = event.size.height, PrevHeight));
				else window->setSize(sf::Vector2u(PrevHeight = PrevWidth = event.size.width, PrevWidth));
			}
		}
		if (!game->isPlaying()) window->close();

		window->clear(sf::Color::Color(28, 28, 28));
		int i = 0;
		for (int j = 0; j < game->CountSnake(); j++)
			for (auto x = game->GetSnake(j)->begin(); x != game->GetSnake(j)->end(); ++x, ++i)
				DrawCircle(mult(snake->GetMatrix(), *x), game->GetSnake(j)->GetColor(i));
		for (int j = 0; j < game->CountEat(); j++)
			DrawCircle(mult(snake->GetMatrix(), *game->GetEatPosition(j)), sf::Color::Red);
		window->display();
		window->setTitle(std::to_string(snake->size()));
	}
}

void Player::CreateWindow()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(PrevWidth, PrevHeight), "", sf::Style::Default, settings);
	cir = new sf::CircleShape(radius);
}

Vector Player::mult(const Matrix& mat, const Vector& vec)
{
	Vector res(mat.size());
	for (int i = 0; i < res.size(); i++) {
		res[i] = 0;
		for (int j = 0; j < mat.size(); j++)
			res[i] += mat(j, i) * vec[j];
	}
	return res;
}

void Player::DrawCircle(Vector coord, sf::Color col)
{
	double len = acos(coord[2]);
	if (len * len < 8) {
		coord[2] = 0;
		if (len > 0.01)	coord.normalize();
		double R = 0;
		if (len < 0.01) R = radius;
		else R = radius * len / sin(len);
		cir->setRadius(R);
		cir->setPosition((coord[0] * len + 1.75) * sizeWindow / 3.5 - R, (-coord[1] * len + 1.75) * sizeWindow / 3.5 - R);
		cir->setFillColor(col);
		window->draw(*cir);
	}
}