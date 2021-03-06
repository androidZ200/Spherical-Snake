#include "GameOfflineMultiplayer.h"

GameOfflineMultiplayer::GameOfflineMultiplayer(Player* player1, Player* player2)
{
	player = new Player * [playerCount];
	player[0] = player1;
	player[1] = player2;
	eat = new Vector[eatCount];
	for (int i = 0; i < eatCount; i++) {
		eat[i] = Vector(3);
		EatGenerate(eat[i]);
	}
	player[0]->SetGameField(this);
	player[1]->SetGameField(this);
	Camera cam;
	cam.GoFront(acos(-1));
	SetStart(player[1]->Snake(), cam);
}

GameOfflineMultiplayer::GameOfflineMultiplayer(const GameOfflineMultiplayer& other)
{
	player = new Player*[playerCount];
	for(int i = 0; i < playerCount; i++)
		player[i] = new Player(*other.player[i]);
	eat = new Vector[eatCount];
	for (int i = 0; i < eatCount; i++)
		eat[i] = other.eat[i];
	player[0]->SetGameField(this);
	player[1]->SetGameField(this);
}

GameOfflineMultiplayer::~GameOfflineMultiplayer()
{
	delete player[0];
	delete player[1];
	delete[] player;
	delete[] eat;
}

GameOfflineMultiplayer& GameOfflineMultiplayer::operator=(const GameOfflineMultiplayer& other)
{
	delete player[0];
	delete player[1];
	delete[] player;
	delete[] eat;

	player = new Player * [playerCount];
	for (int i = 0; i < playerCount; i++)
		player[i] = new Player(*other.player[i]);
	eat = new Vector[eatCount];
	for (int i = 0; i < eatCount; i++)
		eat[i] = other.eat[i];
	player[0]->SetGameField(this);
	player[1]->SetGameField(this);

	return *this;
}

int GameOfflineMultiplayer::CountSnake()
{
	return playerCount;
}

int GameOfflineMultiplayer::CountEat()
{
	return eatCount;
}

Vector* GameOfflineMultiplayer::GetEatPosition(int index)
{
	return eat + index;
}

SnakeBody* GameOfflineMultiplayer::GetSnake(int index)
{
	return player[index]->Snake();
}

bool GameOfflineMultiplayer::isWinPlayerOne()
{
	return isWinPlayer1;
}

void GameOfflineMultiplayer::Tick()
{
	if (!isPause) {
		GetMove(player[0]);
		for (int i = 0; i < eatCount; i++)
			if (Length(player[0]->Snake()->HeadPosition(), eat[i]) < 0.08) {
				IGame::AddSegments(player[0]->Snake(), 5);
				EatGenerate(eat[i]);
			}
		if (LengthToSnake(player[0]->Snake()) < 0.07 || 
			LengthToSnake(player[1]->Snake(), player[0]->Snake()->HeadPosition()) < 0.07) {
			isEndGame = true;
			isWinPlayer1 = false;
		}

		GetMove(player[1]);
		for (int i = 0; i < eatCount; i++)
			if (Length(player[1]->Snake()->HeadPosition(), eat[i]) < 0.08) {
				IGame::AddSegments(player[1]->Snake(), 5);
				EatGenerate(eat[i]);
			}
		if (LengthToSnake(player[1]->Snake()) < 0.07 ||
			LengthToSnake(player[0]->Snake(), player[1]->Snake()->HeadPosition()) < 0.07) {
			isEndGame = true;
			isWinPlayer1 = true;
		}
	}
	player[0]->DrawFrame();
	player[1]->DrawFrame();
}
