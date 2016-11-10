//course: CS216-00x
//Project: Lab Assignment 10
//Date: 11/08/2016
//File: Matrix.cpp
//Purpose: to define the class Matrix
//Author: (your name)

#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;

Matrix::Matrix(int sizeX, int sizeY) : dx(sizeX), dy(sizeY)
{
	assert(sizeX > 0 && sizeY > 0);
	p = new long*[dx];
				// create array of pointers to long integers
	assert(p != 0);
	for (int i = 0; i < dx; i++)
	{	  // for each pointer, create array of long integers
		p[i] = new long[dy];
		assert(p[i] != 0);
		for (int j = 0; j < dy; j++)
			p[i][j] = 0;
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < dx; i++)
		delete [] p[i];	// delete arrays of long integers
	delete [] p;	// delete array of pointers to long
}

long &Matrix::Element(int x, int y)
{
	assert(x >= 0 && x < dx && y >= 0 && y < dy);
	return p[x][y];
}

void Matrix::Print() const
{
	for (int x = 0; x < dx; x++)
	{
		for (int y = 0; y < dy; y++)
			cout << p[x][y] << "\t";
		cout << endl;
	}
}

// ------------------------------------------------------------------
				// my implementation
// ------------------------------------------------------------------

Matrix::Matrix(const Matrix &m){
	p = new long*[m.dx];
	*p = *m.p;
	dx = m.dx;
	dy = m.dy;
	for (int i = 0; i < dx; i++){
		p[i] = new long[dy];
		for (int j = 0; j < dy; j++){
			p[i][j] = m.p[i][j];
		}
	}
}

long & Matrix::operator()(int x, int y){
	return p[x][y];
}

Matrix & Matrix::operator=(const Matrix &m){
	if (this == &m){
		cout << "These are the same object instances\n";
	}
	else {
		int x = m.GetSizeX(), y = m.GetSizeY();
		// Matrix return_matrix(x, y);

		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
					// return_matrix.p[i][j] = m.p[i][j];
					this->p[i][j] = m.p[i][j];
			}
		}
		return *this;
	}
}

ostream & operator<<(ostream &out, const Matrix &m){
	int x = m.GetSizeX(), y = m.GetSizeY();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++){
			cout << m.p[i][j] << "\t";
		}
		cout << endl;
	}
	return cout;
}

Matrix operator+(Matrix m1, Matrix m2){
	int x = m1.GetSizeX(), y = m1.GetSizeY();
	Matrix return_matrix(x, y);

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			return_matrix.p[i][j] = m1.p[i][j] + m2.p[i][j];
		}
	}
	return return_matrix;
}

Matrix operator*(int fac, Matrix m1){
	int x = m1.GetSizeX(), y = m1.GetSizeY();
	Matrix return_matrix(x, y);

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			return_matrix.p[i][j] = m1.p[i][j] * fac;
		}
	}
	return return_matrix;
}

Matrix operator*(Matrix m1, int fac){
	// int x = m1.GetSizeX(), y = m1.GetSizeY();
	// Matrix return_matrix(x, y);
	//
	// for (int i = 0; i < x; i++){
	// 	for (int j = 0; j < y; j++){
	// 		return_matrix[i][j] = m1[i][j] * fac;
	// 	}
	// }
	// return return_matrix;
	return fac * m1;
}

Matrix operator*(Matrix m1, Matrix m2){
	int x1 = m1.GetSizeX(), y1 = m1.GetSizeY(), x2 = m2.GetSizeX(), y2 = m2.GetSizeY();
	Matrix return_matrix(x1, y2);
	long temp;

	for (int i = 0; i < x1; i++){
		for (int j = 0; j < y2; j++){
			temp = 0;
			for (int k = 0; k < y1; k++){
				temp += m1.p[i][k] * m2.p[k][j];
			}
			return_matrix.p[i][j] = temp;
		}
	}


	return return_matrix;
}
