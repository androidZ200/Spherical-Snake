#pragma once
#include <cmath>

#ifdef MATRIX_EXPORTS
#define MATRIX_API __declspec(dllexport)
#else
#define MATRIX_API __declspec(dllimport)
#endif

namespace SquareMat {

	class MATRIX_API Matrix
	{
		int n;
		double* mat;

	public:
		Matrix();
		Matrix(int n);
		Matrix(double* arr, int n);
		Matrix(const Matrix& other);
		Matrix(Matrix&& other);
		~Matrix();

		static Matrix E(int n);
		static Matrix Zero(int n);
		static Matrix Scale(int n, ...);
		static Matrix Rotate(int n, double alpha, int indexVecA, int indexVecB);
		static Matrix Rotate(int n, double sin_alpha, double cos_alpha, int indexVecA, int indexVecB);

		Matrix& operator = (const Matrix& other);
		Matrix& operator = (Matrix&& other);
		Matrix& operator *= (double num);
		Matrix operator * (double num) const;
		Matrix& operator /= (double num);
		Matrix operator / (double num) const;
		Matrix operator * (const Matrix& other) const;
		Matrix& operator *= (const Matrix& other);
		Matrix& operator += (const Matrix& other);
		Matrix operator + (const Matrix& other) const;
		Matrix& operator -= (const Matrix& other);
		Matrix operator - (const Matrix& other) const;

		bool operator ==(const Matrix& other) const;
		bool operator !=(const Matrix& other) const;

		double operator ()(int x, int y) const;
		double& operator ()(int x, int y);
		Matrix& Transpose();
		Matrix GetTranspose() const;
		Matrix& Reverse();
		Matrix GetReverse() const;
		Matrix& AddingRows(int Set, int Get, double C = 1);
		Matrix& AddingColumns(int Set, int Get, double C = 1);
		Matrix& SwapRows(int i, int j);
		Matrix& SwapColumns(int i, int j);
		Matrix& MultiplyRows(int Set, double C);
		Matrix& MultiplyColumns(int Set, double C);
		double GetDeterminant() const;
		Matrix ConverteTo(int newSize) const;

		int size() const;

	private:
		void swap(double& a, double& b);
	};

}