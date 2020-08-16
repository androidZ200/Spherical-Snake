#include "GameSpace.h"

GameSpace::GameSpace() : GameSpace(new SkinLight())
{
}

GameSpace::GameSpace(ISkin* skinSnake)
{
	snake = new SnakeBody(skinSnake);
	eat = Vector(3);
	EatGenerate();
	count = 0;
}

GameSpace::~GameSpace()
{
	delete snake;
}

void GameSpace::Check()
{
	int i = 0;
	for (auto iter = snake->begin(); iter != snake->end(); ++iter, ++i)
		if (i < 31) continue;
		else if (Length(snake->HeadPosition(), *iter) < 0.07) {
			isEndGame = true;
			break;
		}
	if (Length(snake->HeadPosition(), eat) < 0.08) {
		snake->AddSegments(5);
		EatGenerate();
	}
}

bool GameSpace::isPlaying()
{
	return !isEndGame;
}

SnakeBody* GameSpace::Snake()
{
	return snake;
}

void GameSpace::Stop()
{
	isEndGame = true;
}

Vector GameSpace::GetEatPosition()
{
	return eat;
}

int GameSpace::GetCount()
{
	return count;
}

double GameSpace::Length(const Vector& a, const Vector& b)
{
	return acos(a.scal(b));
}

void GameSpace::EatGenerate()
{
	count++;
	srand(time(0));
	do {
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
	} while (LengthToSnake(snake, eat) < 0.3);
}

double GameSpace::LengthToSnake(SnakeBody* snake, const Vector& point)
{
	double min = 1000;
	for (auto x = snake->begin(); x != snake->end(); ++x) {
		double l = Length(*x, point);
		if (l < min) min = l;
	}
	return min;
}
