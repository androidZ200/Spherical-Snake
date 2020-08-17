#pragma once
#include "IConstGame.h"
#include "IPlayer.h"
#include <cmath>

class IGame : public IConstGame
{
public:
	virtual void Tick() = 0;
protected:
	void Move(SnakeBody* snake);
	void Rotate(SnakeBody* snake, bool isRight);
	void AddSegments(SnakeBody* snake, int count);
	void AddGostMide(SnakeBody* snake, int count);
	void DeleteTail(SnakeBody* snake, int count);
	void SetStart(SnakeBody* snake, Camera start);
	double Length(const Vector& a, const Vector& b);
	void EatGenerate(Vector& eat);
	double LengthToSnake(SnakeBody* snake, const Vector& point);
	double LengthToSnake(SnakeBody* snake);
	void GetMove(IPlayer* player);
};

