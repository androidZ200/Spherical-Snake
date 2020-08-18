#pragma once
#include "SnakeBody.h"
#include "IConstGame.h"
#include "IController.h"

class IPlayer {
public:
	virtual SnakeBody* Snake() = 0;
	virtual double GetMove() = 0;
	virtual void SetGameField(IConstGame* game) = 0;
	virtual void DrawFrame() = 0;
};