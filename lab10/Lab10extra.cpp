//course: CS216-00x
//Project: Lab Assignment 10
//Date: 11/08/2016
//Purpose: Implement operator overloading to simplify basic operations on Matrices
//         such as <<, (), +, * operators
//Author: (your name)

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <ctime>
#include "Matrix.h"

using namespace std;

int main(int argc, char** argv) {
    int size1, size2, size3;
    const int RANGE = 2; //using to generate random number in the range[0,1]
        
    cout << "Please input three positive integers to decide the sizes of matrices: ";
    cin >> size1 >> size2 >> size3;
    // Make sure each size is positive, otherwise abort the program
    assert(size1 > 0 && size2 > 0 && size3 > 0);
    
    // Declare Matrix objects with sizes passing in as parameter
    // The system automatically calls the constructor of Matrix class, which takes two parameters
    Matrix myMatrix1(size1, size2);
    
    // Simulate the adjacency matrix for undirected graph
    // Which only stores either 0 or 1 in the matrix
    // where 0 represents no path between two vertices in the grpah
    //       1 represents a path between two vertices in the graph
    srand(time(0));
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            myMatrix1(i,j) = rand() % RANGE;

    Matrix yourMatrix1 = myMatrix1;
    Matrix hisMatrix1 = myMatrix1;
    Matrix herMatrix1 = myMatrix1;
    cout << "myMatrix1: " << endl;
    cout << myMatrix1 << endl << endl;
    
    cout << "yourMatrix1 = myMatrix1: " << endl;
    cout << yourMatrix1 << endl << endl;

    yourMatrix1 = 2 * myMatrix1;
    hisMatrix1 = myMatrix1 + yourMatrix1;
    herMatrix1 = myMatrix1 * 3;
    // hisMatrix1 and herMatrix1 should be identical now, but still independent

    cout << "myMatrix1: " << endl;
    cout << myMatrix1 << endl << endl;
    
    cout << "yourMatrix1 = 2 * myMatrix1: " << endl;
    cout << yourMatrix1 << endl << endl;
    
    cout << "hisMatrix1 = myMatrix1 + yourMatrix1: " << endl;
    cout << hisMatrix1 << endl << endl;

    cout << "herMatrix1 = myMatrix1 * 3: " << endl;
    cout << herMatrix1 << endl << endl;

    // herMatrix1 should be 4 * myMatrix1, and hisMatrix has not been changed
    herMatrix1 = herMatrix1 + myMatrix1;
    cout << "hisMatrix1: " << endl;
    cout << hisMatrix1 << endl << endl;
    cout << "herMatrix1 = herMatrix1 + myMatrix1: " << endl;
    cout << herMatrix1 << endl << endl;

    // Extra part of this Lab assignment
    // You need to define the matrix multiplication in your definition of class Matrix
    Matrix myMatrix2(size2,size3);
    Matrix yourMatrix2(size2, size1);
    Matrix hisMatrix2(size1, size3);
    Matrix herMatrix2(size1, size1);    
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size3; j++)
            myMatrix2(i,j) = rand() % RANGE;
        for (int j = 0; j < size1; j++)
	        yourMatrix2(i,j) = rand() % RANGE;
    }
    hisMatrix2 = myMatrix1 * myMatrix2;
    herMatrix2 = yourMatrix1 * yourMatrix2;
    cout << "myMatrix1: " << endl;
    cout << myMatrix1 << endl << endl;
    
    cout << "myMatrix2: " << endl;
    cout << myMatrix2 << endl << endl;
    
    cout << "hisMatrix2 = myMatrix1 * myMatrix2: " << endl;
    cout << hisMatrix2 << endl << endl;
    
    cout << "yourMatrix1: " << endl;
    cout << yourMatrix1 << endl << endl;
    
    cout << "yourMatrix2: " << endl;
    cout << yourMatrix2 << endl << endl;
    
    cout << "herMatrix2 = yourMatrix1 * yourMatrix2: " << endl;
    cout << herMatrix2 << endl << endl;

    cout << "herMatrix2's square: " << endl;
    cout << herMatrix2*herMatrix2 << endl << endl;    

    return 0;
}

