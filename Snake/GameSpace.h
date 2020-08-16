#pragma once
#include "SnakeBody.h"
#include <cmath>
#include <time.h>

class GameSpace
{
	SnakeBody* snake;
	Vector eat;
	bool isEndGame = false;
	int count;

public:
	GameSpace();
	GameSpace(ISkin* skinSnake);
	~GameSpace();

	void Check();
	bool isPlaying();
	SnakeBody* Snake();
	void Stop();
	Vector GetEatPosition();
	int GetCount();

private:
	double Length(const Vector& a, const Vector& b);
	void EatGenerate();
	double LengthToSnake(SnakeBody* snake, const Vector& point);
};