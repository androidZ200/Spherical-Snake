#pragma once
#include "Matrix.h";
#include "Vector.h"

using namespace SquareMat;

class Camera
{
	Matrix A;
public:
	Camera();
	Camera(Vector pos, Vector front);
	Camera(const Camera& other);
	Camera& operator =(const Camera& other);

	Vector GetFront();
	Vector GetRight();
	Vector GetPosition();

	void GoFront(double step = 0.05);
	void GoBack(double step = 0.05);
	void GoRight(double step = 0.05);
	void GoLeft(double step = 0.05);

	void  Rotate(double angle);
	const Matrix& GetMatrix();

private:
	void move(int a, int b, double teta);
};

