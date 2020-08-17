#pragma once
#include "IGame.h"
#include "Player.h"

class GameOfflineMultiplayer : public IGame
{
	Player** player;
	Vector* eat;
	int eatCount = 2;
	int playerCount = 2;
	bool isWinPlayer1 = true;

public:
	GameOfflineMultiplayer(Player* player1, Player* player2);
	~GameOfflineMultiplayer();

	int CountSnake() override;
	int CountEat() override;
	Vector* GetEatPosition(int index) override;
	SnakeBody* GetSnake(int index) override;
	bool isWinPlayerOne();

	virtual void Tick() override;
};