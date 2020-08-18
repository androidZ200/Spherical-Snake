#include "Player.h"

Player::Player(SnakeBody* snake, IController* controller, SFMLDrawer* drawer)
{
	this->controller = controller;
	this->snake = snake;
	this->drawer = drawer;
	drawer->SetSnake(snake);
	window = drawer->GetWindow();
	controller->SetSnake(snake);
	controller->SetWindow(window);

	PrevHeight = PrevWidth = drawer->GetSizeWindow();
}

Player::Player(const Player& other)
{
	snake = new SnakeBody(*other.snake);
	controller = other.controller->Copy();
	game = other.game;
	drawer = other.drawer->Copy();
	drawer->SetGame(game);
	drawer->SetSnake(snake);
	window = drawer->GetWindow();
	isPausePressed = other.isPausePressed;
	PrevHeight = PrevWidth = drawer->GetSizeWindow();
}

Player::~Player()
{
	delete controller;
	delete snake;
	delete drawer;
}

Player& Player::operator=(const Player& other)
{
	delete controller;
	delete snake;
	delete drawer;

	snake = new SnakeBody(*other.snake);
	controller = other.controller->Copy();
	game = other.game;
	drawer = other.drawer;
	drawer->SetGame(game);
	drawer->SetSnake(snake);
	window = drawer->GetWindow();
	isPausePressed = other.isPausePressed;
	PrevHeight = PrevWidth = drawer->GetSizeWindow();

	return *this;
}

SnakeBody* Player::Snake()
{
	return snake;
}

double Player::GetMove()
{
	return controller->GetMove();
}

void Player::SetGameField(IConstGame* game)
{
	this->game = game;
	drawer->SetGame(game);
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
		drawer->DrawFrame();
	}
}