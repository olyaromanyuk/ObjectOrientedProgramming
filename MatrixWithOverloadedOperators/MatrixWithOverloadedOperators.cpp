// MatrixWithOverloadedOperators.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Matrix{
protected:
	int n;
	int m;
	double ** matrix;
public:
	Matrix() : n(0), m(0), matrix(nullptr){};
	Matrix(int n, int m);
	//Matrix(const Matrix& m);
	//~Matrix();
	int getN() const { return n; };
	int getM() const { return m; };
	double getElement(int i, int j) const { return matrix[i][j]; };
	void setElement(int i, int j, double x) const { matrix[i][j] = x; }

	Matrix operator +(Matrix that);
	//Matrix operator*(Vector vec);
	Matrix operator*(double x);
	Matrix operator=(const Matrix& m){ return *this; };
	Matrix operator*(Matrix that);

};


Matrix::Matrix(int n, int m){
	(*this).n = n;
	(*this).m = m;
	matrix = new double *[n];
	for (int i = 0; i < n; i++){
		matrix[i] = new double[m];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			matrix[i][j] = 0;
		}
	}
}

Matrix Matrix::operator+(Matrix that){
	Matrix null;
	if (getN() != that.getN()){
		cout << "Addition impossible (rows numbers not equal)";
		return null;
	}
	if (getM() != that.getM()){
		cout << "Addition impossible (columns numbers not equal)";
		return null;
	}
	Matrix sum (n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			sum.matrix[i][j] = matrix[i][j] + that.matrix[i][j];
		}
	}
	return sum;
}

Matrix Matrix::operator*(double x){
	Matrix result(n, m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			result.matrix[i][j] = matrix[i][j] * x;
		}
	}
	return result;
}

Matrix Matrix::operator*(Matrix that){
	Matrix null;
	if (m != that.n) {
		cout << "Multiplication impossible" << endl;
		return null;
	}
	Matrix result(n, that.m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < that.m; j++){
			for (int k = 0; k < m; k++){
				result.matrix[i][j] += matrix[i][k] * that.matrix[k][j];
			}
		}
	}
	return result;
}

bool operator==(const Matrix& m1, const Matrix& m2){
	if (m1.getN() != m2.getN()) return false;
	if (m1.getM() != m2.getM()) return false;
	for (int i = 0; i < m1.getN(); i++){
		for (int j = 0; j < m1.getM(); j++){
			if (m1.getElement(i, j) != m2.getElement(i, j)) return false;
		}
	}
	return true;
}
ostream& operator<<(ostream& out, const Matrix& m){
	for (int i = 0; i < m.getN(); i++){
		for (int j = 0; j < m.getM(); j++){
			out << m.getElement(i,j) << " ";
		}
		out << "\n";
	}
	return out;
}
istream& operator>>(istream& in, const Matrix& m){
	cout << "Matrix " << m.getN() << "-by-" << m.getM() << endl;
	for (int i = 0; i < m.getN(); i++){
		for (int j = 0; j < m.getM(); j++){
			cout << "matrix[" << i << "][" << j << "] = ";
			double x;
			in >> x;
			m.setElement(i, j, x);
		}
	}
	return in;
}
int _tmain(int argc, _TCHAR* argv[])
{
	bool cont = true;
	while (cont){
		int n, m;
		cout << "A" << endl;
		cout << "n = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
		Matrix A(n, m);
		cin >> A;

		cout << "B" << endl;
		cout << "n = ";
		cin >> n;
		cout << "m = ";
		cin >> m;
		Matrix B(n,  m);
		cin >> B;

		cout << "x" << endl;
		cout << "n = ";
		cin >> n;
		Matrix x(n, 1);
		cin >> x;

		cout << A << endl;
		cout << B << endl;
		cout << x << endl;

		if (A == B){
			cout << A * 2 * x;
		}
		else{
			cout << (A + B) * x;
		}

		cout << "Do you want to try again? Yes - 1" << endl;
		cin >> n;
		if (n != 1) cont = false;
	}
}

