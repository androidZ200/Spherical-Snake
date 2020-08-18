#pragma once
#include "IGame.h"
#include "Player.h"

class GameZen : public IGame
{
	Player* player;
	Vector* eat;
	int eatCount = 5;

public:
	GameZen(Player* player);
	GameZen(const GameZen& other);
	~GameZen();
	GameZen& operator = (const GameZen& other);

	int CountSnake() override;
	int CountEat() override;
	Vector* GetEatPosition(int index) override;
	SnakeBody* GetSnake(int index) override;

	virtual void Tick() override;
};