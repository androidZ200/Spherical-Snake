#pragma once
#include "IDrawer.h"
#include "SFML/Graphics.hpp"
#include "IConstGame.h"

class SFMLDrawer : public IDrawer
{
protected:
	SnakeBody* snake;
	IConstGame* game;
	sf::RenderWindow* window;
	sf::CircleShape cir;
	sf::Shader shader;
	sf::RenderTexture texture;
	bool isSimple;
	int radius = 9;
	int sizeWindow = 700;

public:
	SFMLDrawer(bool isSimple = false);
	SFMLDrawer(int sizeWindow, bool isSimple = false);
	SFMLDrawer(const SFMLDrawer& other);
	~SFMLDrawer();

	void SetGame(IConstGame* game) override;
	void SetSnake(SnakeBody* snake) override;
	virtual SFMLDrawer* Copy() = 0;
	sf::RenderWindow* GetWindow();
	int GetSizeWindow();

	void DrawFrame() override;

protected:
	void Init();
	void Dispose();
	virtual void DrawCircle(const Vector& coord, sf::Color col) = 0;
};

