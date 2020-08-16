#pragma once
#include "IGame.h"
#include "IPlayer.h"
using namespace System::Threading;

class GameZen : public IGame
{
	IPlayer* player;
	Vector* eat;
	int eatCount = 5;

public:
	GameZen(IPlayer* player);
	~GameZen();

	int CountSnake() override;
	int CountEat() override;
	Vector* GetEatPosition(int index) override;
	SnakeBody* GetSnake(int index) override;

	virtual void Tick() override;
};