#include "pch.h"
#include "Matrix.h"

using namespace SquareMat;

Matrix::Matrix()
{
	mat = 0;
	n = 0;
}
Matrix::Matrix(int n)
{
	this->n = n;
	mat = new double[n*n];
}
Matrix::Matrix(double* arr, int n) : Matrix(n)
{
	for (int i = 0; i < n*n; i++)
		mat[i] = arr[i];
}
Matrix::Matrix(const Matrix& other) : Matrix(other.n)
{
	for (int i = 0; i < n*n; ++i)
		mat[i] = other.mat[i];
}
Matrix::Matrix(Matrix&& other)
{
	n = other.n;
	mat = other.mat;
	other.mat = 0;
}
Matrix::~Matrix()
{
	if(!mat)
		delete[] mat;
}
Matrix& Matrix::operator=(const Matrix& other)
{
	Matrix T(other);
	n = T.n;
	double* t = T.mat;
	T.mat = mat;
	mat = t;
	return *this;
}
Matrix& SquareMat::Matrix::operator=(Matrix&& other)
{
	if (mat) delete[] mat;
	mat = other.mat;
	n = other.n;
	other.mat = 0;
	return *this;
}
Matrix& Matrix::operator*=(double num)
{
	for (int i = 0; i < n*n; ++i)
		mat[i] *= num;
	return *this;
}
Matrix SquareMat::Matrix::operator*(double num) const
{
	return Matrix(*this) *= num;
}
Matrix& SquareMat::Matrix::operator/=(double num)
{
	for (int i = 0; i < n * n; ++i)
		mat[i] /= num;
	return *this;
}
Matrix SquareMat::Matrix::operator/(double num) const
{
	return  Matrix(*this) /= num;
}
Matrix Matrix::operator*(const Matrix& other) const
{
	Matrix t(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			double sum = 0;
			for (int k = 0; k < n; ++k)
				sum += (*this)(k, j) * other(i, k);
			t(i, j) = sum;
		}
	return t;
}
Matrix& Matrix::operator*=(const Matrix& other)
{
	(*this) = (*this) * other;
	return *this;
}
Matrix& Matrix::operator+=(const Matrix& other)
{
	for (int i = 0; i < n*n; ++i)
		mat[i] += other.mat[i];
	return *this;
}
Matrix Matrix::operator+(const Matrix& other) const
{
	Matrix t = *this;
	t += other;
	return t;
}
Matrix& SquareMat::Matrix::operator-=(const Matrix& other)
{
	for (int i = 0; i < n * n; ++i)
		mat[i] -= other.mat[i];
	return *this;
}
Matrix SquareMat::Matrix::operator-(const Matrix& other) const
{
	Matrix t = *this;
	t -= other;
	return t;
}
bool Matrix::operator==(const Matrix& other) const
{
	for (int i = 0; i < n * n; ++i)
		if (mat[i] != other.mat[i]) return false;
	return true;
}
bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}
inline double Matrix::operator()(int x, int y) const
{
	//if (x < 0 || x >= n) throw Matrix();
	//if (y < 0 || y >= n) throw Matrix();
	return mat[x + y * n];
}
inline double& Matrix::operator()(int x, int y)
{
	//if (x < 0 || x >= n) throw Matrix();
	//if (y < 0 || y >= n) throw Matrix();
	return mat[x + y * n];
}
Matrix& Matrix::Transpose()
{
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			swap((*this)(i, j), (*this)(j, i));
	return *this;
}
Matrix SquareMat::Matrix::GetTranspose() const
{
	Matrix t(*this);
	return t.Transpose();
}
Matrix& Matrix::Reverse()
{
	Matrix T = Matrix::E(n);
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j)
			if ((*this)(i, j) != 0) {
				SwapRows(i, j);
				T.SwapRows(i, j);
				break;
			}
			else if (j == n - 1) {
				throw 0;
			}

		double s = (*this)(i, i);
		MultiplyRows(i, 1 / s);
		T.MultiplyRows(i, 1 / s);

		for (int j = 0; j < n; ++j)
			if (i != j) {
				s = (*this)(i, j);
				AddingRows(j, i, -s);
				T.AddingRows(j, i, -s);
			}
	}
	for (int i = 0; i < n * n; ++i)
		mat[i] = T.mat[i];
	return *this;
}
Matrix SquareMat::Matrix::GetReverse() const
{
	Matrix t(*this);
	return t.Reverse();
}
Matrix& Matrix::AddingRows(int Set, int Get, double C)
{
	//if (Set < 0 || Set >= n) throw Matrix();
	//if (Get < 0 || Get >= n) throw Matrix();
	for (int i = 0; i < n; ++i)
		(*this)(i, Set) += (*this)(i, Get) * C;
	return *this;
}
Matrix& Matrix::AddingColumns(int Set, int Get, double C)
{
	//if (Set < 0 || Set >= n) throw Matrix();
	//if (Get < 0 || Get >= n) throw Matrix();
	for (int i = 0; i < n; ++i)
		(*this)(Set, i) += (*this)(Get, i) * C;
	return *this;
}
Matrix& Matrix::SwapRows(int i, int j)
{
	//if (i < 0 || i >= n) throw Matrix();
	//if (j < 0 || j >= n) throw Matrix();
	for (int k = 0; k < n; ++k)
		swap((*this)(k, i), (*this)(k, j));
	return *this;
}
Matrix& Matrix::SwapColumns(int i, int j)
{
	//if (i < 0 || i >= n) throw Matrix();
	//if (j < 0 || j >= n) throw Matrix();
	for (int k = 0; k < n; ++k)
		swap((*this)(i, k), (*this)(j, k));
	return *this;
}
Matrix& Matrix::MultiplyRows(int Set, double C)
{
	for (int i = 0; i < n; ++i)
		(*this)(i, Set) *= C;
	return *this;
}
Matrix& Matrix::MultiplyColumns(int Set, double C)
{
	for (int i = 0; i < n; ++i)
		(*this)(Set, i) *= C;
	return *this;
}
double Matrix::GetDeterminant() const
{
	Matrix t(*this);
	for (int i = 0; i < n; ++i) {
		for(int j = i; j < n; ++j)
			if (t(i, j) != 0) {
				t.SwapRows(i, j);
				break;
			}
			else if (j == n - 1) return 0;
		for (int j = i + 1; j < n; ++j) {
			double s = -t(i, j) / t(i, i);
			t.AddingRows(j, i, s);
		}
	}
	double out = 1;
	for (int i = 0; i < n; ++i) out *= t(i, i);
	return out;
}
Matrix SquareMat::Matrix::ConverteTo(int newSize) const
{
	Matrix T = Matrix::Zero(newSize);
	newSize = min(n, newSize);
	for (int j = 0; j < newSize; ++j)
		for (int i = 0; i < newSize; ++i)
			T(i, j) = (*this)(i, j);
	return T;
}
int Matrix::size() const
{
	return n;
}
void Matrix::swap(double& a, double& b)
{
	double t = a;
	a = b;
	b = t;
}
Matrix Matrix::E(int n)
{
	Matrix t = Matrix::Zero(n);
	for (int i = 0; i < n; ++i)
		t(i, i) = 1;
	return t;
}
Matrix Matrix::Zero(int n)
{
	Matrix t(n);
	for (int i = 0; i < n * n; ++i)
		t.mat[i] = 0;
	return t;
}

Matrix SquareMat::Matrix::Scale(int n, ...)
{
	Matrix T = Matrix::Zero(n);
	double* p = (double*)(&n + 1);
	for (int i = 0; i < n; ++i)
		T(i, i) = *(p++);
	return T;
}

Matrix SquareMat::Matrix::Rotate(int n, double alpha, int indexVecA, int indexVecB)
{
	return Matrix::Rotate(n, sin(alpha), cos(alpha), indexVecA, indexVecB);
}

Matrix SquareMat::Matrix::Rotate(int n, double sin_alpha, double cos_alpha, int indexVecA, int indexVecB)
{
	Matrix T = Matrix::E(n);
	T(indexVecA, indexVecA) = T(indexVecB, indexVecB) = cos_alpha;
	T(indexVecB, indexVecA) = -sin_alpha;
	T(indexVecA, indexVecB) = sin_alpha;
	return T;
}