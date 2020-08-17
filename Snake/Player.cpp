#include "Player.h"

Player::Player(SnakeBody* snake, bool isSimpleGraphics, bool isSphereMode)
{
	this->isSimpleGraphics = isSimpleGraphics;
	this->isSphereMode = isSphereMode;
	this->snake = snake;
	keys.push_back(ControlKeys(sf::Keyboard::Right, sf::Keyboard::Left));
	keys.push_back(ControlKeys(sf::Keyboard::X, sf::Keyboard::Z));

	shader = new sf::Shader();
	shader->setUniform("texture", sf::Shader::CurrentTexture);
	shader->loadFromMemory("#version 330 core\n uniform sampler2D texture;\n uniform float Radius;\n" \
		"void main() {\n if ((gl_FragCoord.x - Radius) * (gl_FragCoord.x - Radius) + (gl_FragCoord.y - Radius) *" \
		"(gl_FragCoord.y - Radius) > Radius * Radius)\n	gl_FragColor = vec4(0.16, 0.16, 0.16, 1);\n else "\
		"gl_FragColor = texture2D(texture, gl_FragCoord.xy / (2*Radius));\n }", sf::Shader::Fragment);
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	settings.depthBits = 24;
	texture = new sf::RenderTexture();
	texture->create(sizeWindow, sizeWindow, settings);
}

Player::~Player()
{
	delete snake;
	delete window;
	delete cir;

	delete shader;
	delete texture;
}

SnakeBody* Player::Snake()
{
	return snake;
}

IPlayer::Move Player::GetMove()
{
	for (auto x = keys.begin(); x != keys.end(); ++x) {
		if(sf::Keyboard::isKeyPressed(x->Right())) return IPlayer::Move::Right;
		if(sf::Keyboard::isKeyPressed(x->Left())) return IPlayer::Move::Left;
	}
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
				if (PrevHeight == event.size.height)
					window->setSize(sf::Vector2u(PrevHeight = PrevWidth = event.size.width, PrevHeight));
				else window->setSize(sf::Vector2u(PrevWidth = PrevHeight = event.size.height, PrevHeight));
			}
		}
		if (!game->isPlaying()) window->close();

		texture->clear(sf::Color::Color(28, 28, 28));
		for (int j = 0; j < game->CountSnake(); j++) {
			int i = 0;
			for (auto x = game->GetSnake(j)->begin(); x != game->GetSnake(j)->end(); ++x, ++i)
				if (i % 2 == 1 || !isSimpleGraphics)
					if(isSphereMode) DrawCircle2(*x, game->GetSnake(j)->GetColor(i));
					else DrawCircle(*x, game->GetSnake(j)->GetColor(i));
		}
		for (int j = 0; j < game->CountEat(); j++)
			if (isSphereMode) DrawCircle2(*game->GetEatPosition(j), sf::Color::Red);
			else DrawCircle(*game->GetEatPosition(j), sf::Color::Red);
		sf::Sprite sp;
		texture->display();
		sp.setTexture(texture->getTexture());
		shader->setUniform("Radius", (float)PrevWidth / 2);
		window->draw(sp, shader);
		window->display();
		window->setTitle(std::to_string(snake->size()));
	}
}

void Player::SetKeys(ControlKeys keys)
{
	this->keys.clear();
	AddKeys(keys);
}

void Player::AddKeys(ControlKeys keys)
{
	this->keys.push_back(keys);
}

void Player::SetGraphicsSettings(bool isSimpleGraphics)
{
	this->isSimpleGraphics = isSimpleGraphics;
}

void Player::CreateWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(PrevWidth, PrevHeight), "");
	cir = new sf::CircleShape(radius);
}

void Player::DrawCircle(const Vector& coord, sf::Color col)
{
	const Matrix& mat = snake->GetMatrix();
	double len = 0; 
	for (int i = 0; i < mat.size(); ++i)
		len += mat(i, 2) * coord[i];
	len = acos(len);
	if (len < 1.82) {
		double x = 0, y = 0;
		for (int i = 0; i < mat.size(); ++i) {
			x += mat(i, 0) * coord[i];
			y += mat(i, 1) * coord[i];
		}
		if (len > 0.1) { 
			double t = sqrt(x*x + y*y);
			x = x * len / t;
			y = y * len / t; 
		}
		double R = 0;
		if (len < 0.1) R = radius;
		else R = radius * len / sin(len);

		cir->setRadius(R);
		cir->setPosition((x + 1.75) * sizeWindow / 3.5 - R, (-y + 1.75) * sizeWindow / 3.5 - R);
		cir->setFillColor(col);
		texture->draw(*cir);
	}
}

void Player::DrawCircle2(const Vector& coord, sf::Color col)
{
	const Matrix& mat = snake->GetMatrix();
	double z = 0;
	for (int i = 0; i < mat.size(); ++i)
		z += mat(i, 2) * coord[i];
	if (z > 0.125) {
		double x = 0, y = 0;
		for (int i = 0; i < mat.size(); ++i) {
			x += mat(i, 0) * coord[i];
			y += mat(i, 1) * coord[i];
		}
		x = x / (8 - z) * 8 * 1.75;
		y = y / (8 - z) * 8 * 1.75;

		double R = radius * 1.75;
		cir->setOrigin(sf::Vector2f(R, R));
		cir->setScale(z, 1);
		cir->setRotation(-atan2(y, x) / acos(-1) * 180);

		cir->setRadius(R);
		cir->setPosition((x + 1.75) * sizeWindow / 3.5, (-y + 1.75) * sizeWindow / 3.5);
		cir->setFillColor(col);
		texture->draw(*cir);
	}
}
