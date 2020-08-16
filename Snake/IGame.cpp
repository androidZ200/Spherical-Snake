#include "IGame.h"


void IGame::Move(SnakeBody* snake)
{
	snake->Move();
}

void IGame::Rotate(SnakeBody* snake, bool isRight)
{
	snake->Rotate(isRight);
}

void IGame::AddSegments(SnakeBody* snake, int count)
{
	snake->AddSegments(count);
}

void IGame::AddGostMide(SnakeBody* snake, int count)
{
	snake->AddGostMode(count);
}

void IGame::DeleteTail(SnakeBody* snake, int count)
{
	snake->DeleteTail(count);
}

double IGame::Length(const Vector& a, const Vector& b)
{
	return acos(a.scal(b));
}

void IGame::EatGenerate(Vector& eat)
{
	double a, b, c, d;
	a = b = (rand() % 10001) / 10000.0;
	c = 1.0 - a;
	d = (rand() % 10001) / 10000.0;
	a *= d;
	b *= (1.0 - d);
	d = (rand() % 10001) / 10000.0;
	c *= d;
	a = sqrt(a);
	b = sqrt(b);
	c = sqrt(c);
	if (rand() % 2 == 0) a *= -1;
	if (rand() % 2 == 0) b *= -1;
	if (rand() % 2 == 0) c *= -1;
	eat[0] = a;
	eat[1] = b;
	eat[2] = c;
	eat.normalize();
}

double IGame::LengthToSnake(SnakeBody* snake, const Vector& point)
{
	double min = 1000;
	for (auto x = snake->begin(); x != snake->end(); ++x) {
		double l = Length(*x, point);
		if (l < min) min = l;
	}
	return min;
}

void IGame::GetMove(IPlayer* player)
{
	Move(player->Snake());
	IPlayer::Move rot = player->GetMove();
	if (rot == IPlayer::Move::Right)
		Rotate(player->Snake(), true);
	else if (rot == IPlayer::Move::Left)
		Rotate(player->Snake(), false);
}