#pragma once
#include "IController.h"
#include "ControlKeys.h"
#include <list>

class KeysController : public IController
{
	std::list<ControlKeys> keys;
	double t = 0;

public:
	KeysController();
	KeysController(ControlKeys keys);
	KeysController(const KeysController& other);

	double GetMove() override;
	IController* Copy() override;
	void SetSnake(SnakeBody* snake) override;
	void SetWindow(sf::RenderWindow* window) override;

	void AddKeys(ControlKeys keys);
	void Clear();
};

