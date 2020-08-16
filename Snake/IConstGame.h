#pragma once
#include "SnakeBody.h"

class IConstGame
{
protected:
	bool isEndGame = false;
	bool isPause = false;
public:
	virtual int CountSnake() = 0;
	virtual int CountEat() = 0;
	virtual Vector* GetEatPosition(int index) = 0;
	virtual SnakeBody* GetSnake(int index) = 0;

	bool isPlaying();
	void Stop();
	void PlayPause();
};