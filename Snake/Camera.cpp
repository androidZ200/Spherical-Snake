#include "Camera.h"

Camera::Camera()
{
	A = Matrix::E(3);
}

Camera::Camera(Vector pos, Vector front)
{
	A = Matrix(3);
	A(0, 2) = pos[0];
	A(1, 2) = pos[1];
	A(2, 2) = pos[2];
	A(0, 1) = front[0];
	A(1, 1) = front[1];
	A(2, 1) = front[2];
	A(0, 0) = A(1, 1) * A(2, 2) - A(2, 1) * A(1, 2);
	A(1, 0) = A(2, 1) * A(0, 2) - A(0, 1) * A(2, 2);
	A(2, 0) = A(0, 1) * A(1, 2) - A(1, 1) * A(0, 2);
}

Camera::Camera(const Camera& other)
{
	A = other.A;
}

Camera& Camera::operator=(const Camera& other)
{
	*this = Camera(other);
	return *this;
}

Vector Camera::GetFront()
{
	return Vector(&A(0, 1), 3);
}

Vector Camera::GetRight()
{
	return Vector(&A(0, 0), 3);
}

Vector Camera::GetPosition()
{
	return Vector(&A(0, 2), 3);
}

void Camera::GoFront(double step)
{
	move(1, 2, step);
}

void Camera::GoBack(double step)
{
	GoFront(-step);
}

void Camera::GoRight(double step)
{
	move(0, 2, step);
}

void Camera::GoLeft(double step)
{
	GoRight(-step);
}

void Camera::Rotate(double angle)
{
	move(1, 0, angle);
}

const Matrix& Camera::GetMatrix()
{
	return A;
}

void Camera::move(int a, int b, double teta)
{
	double c = cos(teta);
	double s = sin(teta);

	Matrix Rotate = Matrix::E(3);
	Rotate(a, a) = Rotate(b, b) = c;
	Rotate(b, a) = -s;
	Rotate(a, b) = s;
	A = Rotate * A;
}
