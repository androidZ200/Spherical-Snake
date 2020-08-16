#include "GameClassic.h"

GameClassic::GameClassic(IPlayer* player)
{
	this->player = player;
	eat = Vector(3);
	do { EatGenerate(eat); } while (LengthToSnake(player->Snake(), eat) < 0.3);
	player->SetGameField(this);
}

GameClassic::~GameClassic()
{
	delete player;
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
			do { EatGenerate(eat); } while (LengthToSnake(player->Snake(), eat) < 0.3);
		}

		int i = 0;
		for (auto x = player->Snake()->begin(); x != player->Snake()->end(); ++x, ++i)
			if (i < 31) continue;
			else if (Length(player->Snake()->HeadPosition(), *x) < 0.07) {
				isEndGame = true;
				break;
			}
	}
	player->DrawFrame();
}