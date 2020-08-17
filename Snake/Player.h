#pragma once
#include "IPlayer.h"
#include "SFML/Graphics.hpp"
#include "ControlKeys.h"
#include <cmath>

class Player : public IPlayer
{
	SnakeBody* snake;
	IConstGame* game;
	std::list<ControlKeys> keys;
	sf::RenderWindow* window;
	sf::CircleShape* cir;
	sf::Shader* shader;
	sf::RenderTexture* texture;
	bool isPausePressed = false;
	bool isSimpleGraphics = false;
	bool isSphereMode = false;
	int radius = 9;
	int sizeWindow = 700;
	int PrevWidth = sizeWindow;
	int PrevHeight = sizeWindow;

public:
	Player(SnakeBody* snake, bool isSimpleGraphics = false, bool isSphereMode = false);
	~Player();

	SnakeBody* Snake() override;
	Move GetMove() override;
	void SetGameField(IConstGame* game) override;
	void DrawFrame() override;
	void SetKeys(ControlKeys keys);
	void AddKeys(ControlKeys keys);
	void SetGraphicsSettings(bool isSimpleGraphics);
private:
	void CreateWindow();
	void DrawCircle(const Vector& coord, sf::Color col);
	void DrawCircle2(const Vector& coord, sf::Color col);
};

