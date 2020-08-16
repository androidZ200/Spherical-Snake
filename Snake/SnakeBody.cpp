#include "SnakeBody.h"

SnakeBody::SnakeBody() : SnakeBody(new SkinLight())
{
}

SnakeBody::SnakeBody(ISkin* skin)
{
	this->skin = skin;
	addSegments += 20;
	Rot = Matrix::E(3);
}

SnakeBody::~SnakeBody()
{
	delete skin;
}

void SnakeBody::Move()
{
	if (addSegments > 0) addSegments--;
	else body.pop_front();
	head.GoFront(0.03);
	body.push_back(head.GetPosition());

	if (maxRotate > 0.04)
		maxRotate -= 0.01;
}

void SnakeBody::Rotate(bool isRight)
{
	if (isRight) { head.Rotate(-maxRotate);  Rot = Matrix::Rotate(3, maxRotate, 1, 0) * Rot; }
	else { head.Rotate(maxRotate); Rot = Matrix::Rotate(3, maxRotate, 0, 1) * Rot;	}

	if (maxRotate < 0.18)
		maxRotate += 0.02;
}

void SnakeBody::AddSegments(int count)
{
	addSegments += count;
}

Matrix SnakeBody::GetMatrix()
{
	return Rot * head.GetMatrix();
}

Vector SnakeBody::HeadPosition()
{
	return head.GetPosition();
}

int SnakeBody::size()
{
	return body.size();
}

sf::Color SnakeBody::GetColor(int index)
{
	return skin->ColorSegment(index);
}

std::list<Vector>::reverse_iterator SnakeBody::begin()
{
	return body.rbegin();
}

std::list<Vector>::reverse_iterator SnakeBody::end()
{
	return body.rend();
}