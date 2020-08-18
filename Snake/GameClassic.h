#pragma once
#include "IGame.h"
#include "Player.h"

class GameClassic : public IGame
{
	Player* player;
	Vector eat;

public:
	GameClassic(Player* player);
	GameClassic(const GameClassic& other);
	~GameClassic();
	GameClassic& operator = (const GameClassic& other);

	int CountSnake() override;
	int CountEat() override;
	Vector* GetEatPosition(int index) override;
	SnakeBody* GetSnake(int index) override;

	virtual void Tick() override;
};