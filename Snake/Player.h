#pragma once
#include "IPlayer.h"
#include "SFML/Graphics.hpp"
#include "ControlKeys.h"
#include "SFMLDrawer.h"
#include <cmath>

class Player : public IPlayer
{
	SnakeBody* snake;
	IConstGame* game;
	IController* controller;
	SFMLDrawer* drawer;
	sf::RenderWindow* window;
	bool isPausePressed = false;
	int PrevWidth;
	int PrevHeight;

public:
	Player(SnakeBody* snake, IController* controller, SFMLDrawer* drawer);
	Player(const Player& other);
	~Player();
	Player& operator = (const Player& other);

	SnakeBody* Snake() override;
	double GetMove() override;
	void SetGameField(IConstGame* game) override;
	void DrawFrame() override;
};

