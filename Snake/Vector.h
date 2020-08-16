#pragma once
#include <math.h>

class Vector
{
	double* vec;
	unsigned int length;

public:
	Vector();
	Vector(int length);
	Vector(double* vec, int Length);
	Vector(const Vector& other);
	Vector(Vector&& other);
	~Vector();

	Vector& operator = (const Vector& other);
	Vector& operator = (Vector&& other);
	Vector& operator += (const Vector& other);
	Vector operator + (const Vector& other) const;
	Vector& operator -= (const Vector& other);
	Vector operator - (const Vector& other) const;
	Vector& operator *= (double num);
	Vector operator * (double num) const;
	Vector& operator /= (double num);
	Vector operator / (double num) const;
	double operator [](int x) const;
	double& operator [](int x);

	bool operator ==(const Vector& other) const;
	bool operator !=(const Vector& other) const;

	double scal(const Vector& other) const;
	double modul() const;
	Vector& normalize();
	unsigned int size() const;
};

