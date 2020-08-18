#pragma once
#include "Camera.h"
#include <list>
#include "Skins.h"

class SnakeBody
{
	friend class IGame;
	Camera head;
	Matrix Rot;
	Matrix Output;
	ISkin* skin;
	std::list<Vector> body;
	int addSegments = 0;
	int gostMode = 0;
	bool isNewMatrix = true;

public:

	SnakeBody();
	SnakeBody(const SnakeBody& other);
	SnakeBody(ISkin* skin);
	~SnakeBody();
	SnakeBody& operator = (const SnakeBody& other);

	bool isGostMode();
	const Matrix& GetMatrix();
	Vector HeadPosition();
	Vector Front();
	int size();
	sf::Color GetColor(int index);
	std::list<Vector>::reverse_iterator begin();
	std::list<Vector>::reverse_iterator end();

private:
	void Move();
	void Rotate(double angle);
	void AddSegments(int count);
	void AddGostMode(int count);
	void DeleteTail(int count);
	void StartPosition(Camera head);
};

