#pragma once
#include "SnakeBody.h"
#include "IConstGame.h"

class IPlayer {
public:
	enum Move { Right, Left, None };

	virtual SnakeBody* Snake() = 0;
	virtual Move GetMove() = 0;
	virtual void SetGameField(IConstGame* game) = 0;
	virtual void DrawFrame() = 0;
};