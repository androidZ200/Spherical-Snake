#include "SnakeBody.h"

SnakeBody::SnakeBody() : SnakeBody(new SkinLight())
{
}

SnakeBody::SnakeBody(const SnakeBody& other)
{
	head = other.head;
	Rot = other.Rot;
	isNewMatrix = true;
	body = other.body;
	addSegments = other.addSegments;
	gostMode = other.gostMode;
	skin = SkinGenerate::toIndex(other.skin->IndexSkin());
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

SnakeBody& SnakeBody::operator=(const SnakeBody& other)
{
	delete skin;
	head = other.head;
	Rot = other.Rot;
	isNewMatrix = true;
	body = other.body;
	addSegments = other.addSegments;
	gostMode = other.gostMode;
	skin = SkinGenerate::toIndex(other.skin->IndexSkin());

	return *this;
}

void SnakeBody::Move()
{
	if (gostMode > 0) gostMode--;
	if (addSegments > 0) addSegments--;
	else body.pop_front();
	head.GoFront(0.03);
	body.push_back(head.GetPosition());

	isNewMatrix = true;
}

void SnakeBody::Rotate(double angle)
{
	if (angle < -1) angle = -1;
	else if (angle > 1) angle = 1;
	angle /= 6;
	head.Rotate(angle);  
	Rot = Matrix::Rotate(3, angle, 0, 1) * Rot;

	isNewMatrix = true;
}

bool SnakeBody::isGostMode()
{
	return gostMode > 0;
}

void SnakeBody::AddSegments(int count)
{
	addSegments += count;
}

void SnakeBody::AddGostMode(int count)
{
	gostMode += count;
}

void SnakeBody::DeleteTail(int count)
{
	for (int i = 0; i < count; i++)
		body.pop_front();
}

void SnakeBody::StartPosition(Camera head)
{
	this->head = head;
}

const Matrix& SnakeBody::GetMatrix()
{
	if (isNewMatrix) {
		Output = Rot * head.GetMatrix();
		isNewMatrix = false;
	}
	return Output;
}

Vector SnakeBody::HeadPosition()
{
	return head.GetPosition();
}

Vector SnakeBody::Front()
{
	Vector t(2);
	t[0] = Rot(1, 0);
	t[1] = Rot(1, 1);
	return t;
}

int SnakeBody::size()
{
	return body.size();
}

sf::Color SnakeBody::GetColor(int index)
{
	sf::Color c = skin->ColorSegment(index);
	if (gostMode > 0) c.a = 100;
	return c;
}

std::list<Vector>::reverse_iterator SnakeBody::begin()
{
	return body.rbegin();
}

std::list<Vector>::reverse_iterator SnakeBody::end()
{
	return body.rend();
}