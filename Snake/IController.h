#pragma once
#include "SnakeBody.h"
#include "SFML/Graphics.hpp"

class IController {
public:
	virtual double GetMove() = 0;
	virtual IController* Copy() = 0;
	virtual void SetSnake(SnakeBody* snake) = 0;
	virtual void SetWindow(sf::RenderWindow* window) = 0;
};