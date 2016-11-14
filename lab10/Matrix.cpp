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

// copy constructor
Matrix::Matrix(const Matrix &m){
	p = new long*[m.dx]; // declare pointer to new object instance
	// data members
	*p = *m.p;
	dx = m.dx;
	dy = m.dy;
	// copy matrix elements
	for (int i = 0; i < dx; i++){
		p[i] = new long[dy];
		for (int j = 0; j < dy; j++){
			p[i][j] = m.p[i][j];
		}
	}
}

// parentheses operator overloader
long & Matrix::operator()(int x, int y){
	return p[x][y];
}

// assignment operator overloader
Matrix & Matrix::operator=(const Matrix &m){
	if (this == &m){ // check if the objects are the same
		cout << "These are the same object instances\n";
	}
	else {
		int x = m.GetSizeX(), y = m.GetSizeY(); // get matrix dimensions

		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
					this->p[i][j] = m.p[i][j]; // copy elements to new object instace
			}
		}
		return *this; // return this instance
	}
}

// insertion operator overloader
ostream & operator<<(ostream &out, const Matrix &m){
	int x = m.GetSizeX(), y = m.GetSizeY();
	for (int i = 0; i < x; i++) // iterate over all elements
	{
		for (int j = 0; j < y; j++){
			cout << m.p[i][j] << "\t"; // print element separated by tabs
		}
		cout << endl; // print new line after each row
	}
	return cout; // return output
}

// addition operator overloader
Matrix operator+(Matrix m1, Matrix m2){
	int x = m1.GetSizeX(), y = m1.GetSizeY();
	Matrix return_matrix(x, y); // declare new object instance

	for (int i = 0; i < x; i++){ // iterate over the two matrices [they must both be the same dimensions]
		for (int j = 0; j < y; j++){
			return_matrix.p[i][j] = m1.p[i][j] + m2.p[i][j]; // add the two arrays into the new object instance
		}
	}
	return return_matrix; // return the new object instance
}

// multiplication operator overloader
Matrix operator*(int fac, Matrix m1){
	int x = m1.GetSizeX(), y = m1.GetSizeY();
	Matrix return_matrix(x, y); // declare new instance of object

	for (int i = 0; i < x; i++){ // iterate over array
		for (int j = 0; j < y; j++){
			return_matrix.p[i][j] = m1.p[i][j] * fac; // multiply each element by scalar
		}
	}
	return return_matrix; // return new matric instance
}

// multiplication opertor overloader -- the opposite direction
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
	return fac * m1; // this will automatically call the previous multiplication operator overloader
}

// multiplication operator overloader -- two matrices
Matrix operator*(Matrix m1, Matrix m2){
	int x1 = m1.GetSizeX(), y1 = m1.GetSizeY(), x2 = m2.GetSizeX(), y2 = m2.GetSizeY();
	Matrix return_matrix(x1, y2); // declare new object instance
	long temp;

	for (int i = 0; i < x1; i++){ // iterare over the first matrix's rows
		for (int j = 0; j < y2; j++){ // iterate over the second matrix's columns
			temp = 0;
			for (int k = 0; k < y1; k++){ // iterate over both the first matrix's columns and the second matrix's rows -- the dimensions should be equal
				temp += m1.p[i][k] * m2.p[k][j]; // cross product
			}
			return_matrix.p[i][j] = temp; // assign the cross product to the new object instance element
		}
	}


	return return_matrix; // return the new object instance 
}
