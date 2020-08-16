#pragma once
#include "Camera.h"
#include <list>
#include "Skins.h"

class SnakeBody
{
	Camera head;
	Matrix Rot;
	ISkin* skin;
	std::list<Vector> body;
	int addSegments = 0;
	float maxRotate = 0.04;

public:

	SnakeBody();
	SnakeBody(ISkin* skin);
	~SnakeBody();

	void Move();
	void Rotate(bool isRight);
	void AddSegments(int count);
	Matrix GetMatrix();
	Vector HeadPosition();
	int size();
	sf::Color GetColor(int index);
	std::list<Vector>::reverse_iterator begin();
	std::list<Vector>::reverse_iterator end();
};

