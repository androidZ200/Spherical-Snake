#include "Vector.h"

Vector::Vector()
{
	length = 0;
	vec = new double[0];
}
Vector::Vector(int length)
{
	this->length = length;
	vec = new double[length];
	for (int i = 0; i < length; i++)
		vec[i] = 0;
}
Vector::Vector(double* vec, int Length)
{
	length = Length;
	this->vec = new double[length];
	for (int i = 0; i < length; i++)
		this->vec[i] = vec[i];
}
Vector::Vector(const Vector& other)
{
	length = other.length;
	vec = new double[length];
	for (int i = 0; i < length; i++)
		vec[i] = other.vec[i];
}
Vector::Vector(Vector&& other)
{
	length = other.length;
	vec = other.vec;
	other.vec = 0;
}
Vector::~Vector()
{
	delete[] vec;
}
Vector& Vector::operator=(const Vector& other)
{
	Vector t(other);
	double *tt = vec;
	vec = t.vec;
	t.vec = tt;
	length = t.length;
	return *this;
}
Vector& Vector::operator=(Vector&& other)
{
	delete[] vec;
	vec = other.vec;
	length = other.length;
	other.vec = 0;
	return *this;
}
Vector& Vector::operator+=(const Vector& other)
{
	for (int i = 0; i < (length < other.length ? length : other.length); i++)
		vec[i] += other.vec[i];
	return *this;
}
Vector Vector::operator+(const Vector& other) const
{
	Vector t(*this);
	t += other;
	return t;
}
Vector& Vector::operator-=(const Vector& other)
{
	for (int i = 0; i < (length < other.length ? length : other.length); i++)
		vec[i] -= other.vec[i];
	return *this;
}
Vector Vector::operator-(const Vector& other) const
{
	Vector t(*this);
	t -= other;
	return t;
}
Vector& Vector::operator*=(double num)
{
	for (int i = 0; i < length; i++)
		vec[i] *= num;
	return *this;
}
Vector Vector::operator*(double num) const
{
	Vector t(*this);
	t *= num;
	return t;
}
Vector& Vector::operator/=(double num)
{
	for (int i = 0; i < length; i++)
		vec[i] /= num;
	return *this;
}
Vector Vector::operator/(double num) const
{
	Vector t(*this);
	t /= num;
	return t;
}
double Vector::operator[](int x) const
{
	if (x < 0 || x >= length) throw Vector();
	return vec[x];
}
double& Vector::operator[](int x)
{
	if (x < 0 || x >= length) throw Vector();
	return vec[x];
}
bool Vector::operator==(const Vector& other) const
{
	if (length != other.length) return false;
	for (int i = 0; i < length; i++)
		if (vec[i] != other.vec[i]) return false;
	return true;
}
bool Vector::operator!=(const Vector& other) const
{
	return !(*this == other);
}
double Vector::scal(const Vector& other) const
{
	double t = 0;
	for (int i = 0; i < (length < other.length ? length : other.length); i++)
		t += vec[i] * other.vec[i];
	return t;
}
double Vector::modul() const
{
	double t = 0;
	for (int i = 0; i < length; i++)
		t += vec[i] * vec[i];
	return sqrt(t);
}
Vector& Vector::normalize()
{
	double s = modul();
	if (s == 0) return *this;
	for (int i = 0; i < length; i++)
		vec[i] /= s;
	return *this;
}
unsigned int Vector::size() const
{
	return length;
}
