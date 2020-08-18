#pragma once
#include "IController.h"

class MouseController : public IController
{
	SnakeBody* snake;
	sf::RenderWindow* window;
public:
	double GetMove() override;
	IController* Copy() override;
	void SetSnake(SnakeBody* snake) override;
	void SetWindow(sf::RenderWindow* window) override;
};

