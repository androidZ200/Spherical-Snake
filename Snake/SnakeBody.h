#pragma once
#include "Camera.h"
#include <list>
#include "Skins.h"

class SnakeBody
{
	friend class IGame;
	Camera head;
	Matrix Rot;
	ISkin* skin;
	std::list<Vector> body;
	int addSegments = 0;
	float maxRotate = 0.04;
	int gostMode = 0;

public:

	SnakeBody();
	SnakeBody(ISkin* skin);
	~SnakeBody();

	bool isGostMode();
	Matrix GetMatrix();
	Vector HeadPosition();
	int size();
	sf::Color GetColor(int index);
	std::list<Vector>::reverse_iterator begin();
	std::list<Vector>::reverse_iterator end();

private:
	void Move();
	void Rotate(bool isRight);
	void AddSegments(int count);
	void AddGostMode(int count);
	void DeleteTail(int count);
};

