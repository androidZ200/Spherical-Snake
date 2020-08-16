#pragma once
#include "IPlayer.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <thread>
using namespace System::Threading;

class Player : public IPlayer
{
	SnakeBody* snake;
	IConstGame* game;
	sf::RenderWindow* window;
	sf::CircleShape* cir;
	std::thread graph;
	bool isPausePressed = false;
	int radius = 8;
	int sizeWindow = 600;
	int PrevWidth = sizeWindow;
	int PrevHeight = sizeWindow;

public:
	Player(SnakeBody* snake);
	~Player();

	SnakeBody* Snake() override;
	Move GetMove() override;
	void SetGameField(IConstGame* game) override;
	void DrawFrame() override;

private:
	void CreateWindow();
	void LoopGraphics();
	Vector mult(const Matrix& mat, const Vector& vec);
	void DrawCircle(Vector coord, sf::Color col);
};

