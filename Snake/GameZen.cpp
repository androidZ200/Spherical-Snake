#include "GameZen.h"

GameZen::GameZen(IPlayer* player)
{
	this->player = player;
	eat = new Vector[eatCount];
	for (int i = 0; i < eatCount; i++) {
		eat[i] = Vector(3);
		do { EatGenerate(eat[i]); } while (LengthToSnake(player->Snake(), eat[i]) < 0.1);
	}
	player->SetGameField(this);
}

GameZen::~GameZen()
{
	delete player;
	delete[] eat;
}

int GameZen::CountSnake()
{
	return 1;
}

int GameZen::CountEat()
{
	return eatCount;
}

Vector* GameZen::GetEatPosition(int index)
{
	return eat + index;
}

SnakeBody* GameZen::GetSnake(int index)
{
	return player->Snake();
}

void GameZen::Tick()
{
	if (!isPause) {
		GetMove(player);

		for(int i = 0; i < eatCount; i++)
			if (Length(player->Snake()->HeadPosition(), eat[i]) < 0.08) {
				IGame::AddSegments(player->Snake(), 5);
				do { EatGenerate(eat[i]); } while (LengthToSnake(player->Snake(), eat[i]) < 0.1);
			}

			if (LengthToSnake(player->Snake()) < 0.07 && !player->Snake()->isGostMode()) {
				IGame::DeleteTail(player->Snake(), 20);
				IGame::AddGostMide(player->Snake(), 40);
			}
	}
	player->DrawFrame();
}
