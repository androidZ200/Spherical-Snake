#pragma once
#include "IConstGame.h"

class IDrawer {
public:

	virtual void SetGame(IConstGame* game) = 0;
	virtual void SetSnake(SnakeBody* snake) = 0;
	virtual IDrawer* Copy() = 0;

	virtual void DrawFrame() = 0;
};