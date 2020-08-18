#include "GameClassic.h"

GameClassic::GameClassic(Player* player)
{
	this->player = player;
	eat = Vector(3);
	do { EatGenerate(eat); } while (LengthToSnake(player->Snake(), eat) < 0.3);
	player->SetGameField(this);
}

GameClassic::GameClassic(const GameClassic& other)
{
	player = new Player(*other.player);
	eat = other.eat;
	player->SetGameField(this);
}

GameClassic::~GameClassic()
{
	delete player;
}

GameClassic& GameClassic::operator=(const GameClassic& other)
{
	delete player;
	player = new Player(*other.player);
	eat = other.eat;
	player->SetGameField(this);
	return *this;
}

int GameClassic::CountSnake()
{
	return 1;
}

int GameClassic::CountEat()
{
	return 1;
}

Vector* GameClassic::GetEatPosition(int index)
{
	return &eat;
}

SnakeBody* GameClassic::GetSnake(int index)
{
	return player->Snake();
}

void GameClassic::Tick()
{
	if (!isPause) {
		GetMove(player);

		if (Length(player->Snake()->HeadPosition(), eat) < 0.08) {
			IGame::AddSegments(player->Snake(), 5);
			do { EatGenerate(eat); } while (LengthToSnake(player->Snake(), eat) < 0.13);
		}

		if (LengthToSnake(player->Snake()) < 0.07)
			isEndGame = true;
	}
	player->DrawFrame();
}