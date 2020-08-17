#pragma once
#include "IGame.h"
#include "IPlayer.h"

class GameClassic : public IGame
{
	IPlayer* player;
	Vector eat;

public:
	GameClassic(IPlayer* player);
	~GameClassic();

	int CountSnake() override;
	int CountEat() override;
	Vector* GetEatPosition(int index) override;
	SnakeBody* GetSnake(int index) override;

	virtual void Tick() override;
};