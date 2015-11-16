// matrix.cpp : Defines the entry point for the console application.
// 

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;


template<typename T>
T** initRandom(int n, int m)
{
	T** X = new int*[n];
	for (int i = 0; i < n; i++)
	{
		X[i] = new int[m];
		for (int j = 0; j < m; j++){
			cout << "X[" << i << "][" << j << "] = ";
			cin >> X[i][j];
		}
	}
	return X;
}

template<typename T>
void output(T** X, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << " " << X[i][j];
		cout << endl;
	}
	cout << endl;
}

template<typename T>
T** transpose(T** X, int n, int m)
{
	T** xTrans;
	xTrans = new int*[m];
	for (int i = 0; i < m; i++)
	{
		xTrans[i] = new int[n];
		for (int j = 0; j < n; j++)
			xTrans[i][j] = X[j][i];
	}
	return xTrans;
}

template<typename T>
T** add(T** X, T** Y, int n, int m)
{
	T** sum;
	sum = new int*[n];
	for (int i = 0; i < n; i++)
	{
		sum[i] = new int[m];
		for (int j = 0; j < m; j++)
			sum[i][j] = X[i][j] + Y[i][j];
	}
	return sum;
}

template<typename T>
T** substract(T** X, T** Y, int n, int m)
{
	T** diff;
	diff = new int*[n];
	for (int i = 0; i < n; i++)
	{
		diff[i] = new int[m];
		for (int j = 0; j < m; j++)
			diff[i][j] = X[i][j] - Y[i][j];
	}
	return diff;
}

template<typename T>
T** multiply(T** X, T** Y, int n1, int m1, int n2, int m2)
{
	T** prod;
	prod = new int*[n1];
	for (int i = 0; i < n1; i++)
	{
		prod[i] = new int[m2];
		for (int j = 0; j < m2; j++)
		{
			prod[i][j] = 0;
			for (int k = 0; k < n2; k++)
				prod[i][j] += X[i][k] * Y[k][j];
		}
	}
	return prod;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n1;
	cout << "n1 = ";
	cin >> n1;
	int m1;
	cout << "m1 = ";
	cin >> m1;
	int n2;
	cout << "n2 = ";
	cin >> n2;
	int m2;
	cout << "m2 = ";
	cin >> m2;

	int **a, **b, **aTrans, **sum, **diff, **prod;

	a = initRandom<int>(n1, m1);
	b = initRandom<int>(n2, m2);

	output(a, n1, m1);
	output(b, n2, m2);

	cout << "transposed : " << endl;
	output(transpose(a, n1, m1), m1, n1);

	if ((n1 != n2) || (m1 != m2)) cout << "Addition and substraction impossible\n";
	else
	{
		cout << "addition : " << endl;
		output(add(a, b, n1, m1), n1, m1);
		cout << "substraction : " << endl;
		output(substract(a, b, n1, m1), n1, m1);
	}

	if (m1 != n2) cout << "Multiplication impossible";
	else
	{
		cout << "multiplication : " << endl;
		output(multiply(a, b, n1, m1, n2, m2), n1, m2);
	}


	cin >> n1;
	return 0;
}