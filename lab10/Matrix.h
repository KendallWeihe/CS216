//File: Matrix.h
//Purpose: to declare the class Matrix
//Author: (your name)

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
  public:
    Matrix(int sizeX, int sizeY);
    Matrix(const Matrix &m);   // copy constructor
    ~Matrix();
    int GetSizeX() const { return dx; }
    int GetSizeY() const { return dy; }
    long &Element(int x, int y);        // return reference to an element
    void Print() const;
    long &operator()(int x, int y);  // () operator overloading
    Matrix &operator=(const Matrix &m);  // = operator overloading
    friend ostream &operator<<(ostream &out, const Matrix &m); // << operator overloading
    friend Matrix operator+(Matrix m1, Matrix m2); // binary + operator overloading
    friend Matrix operator*(int fac, Matrix m1);   // binary * operator overloading
    friend Matrix operator*(Matrix m1, int fac);   // binary * operator overloading
    friend Matrix operator*(Matrix m1, Matrix m2);

  private:
    long **p;       // pointer to a pointer to a long integer
    int dx, dy;
};

#endif	/* MATRIX_H */
