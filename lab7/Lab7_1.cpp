//course: CS216-00x
//Project: Lab Assignment 7
//Program: Lab7_1.cpp
//Date: 10/18/2016
//Purpose: Use as the lab assignment example
//
//Author: (your name)


#include <iostream>
#include <string>
using namespace std;

//define our own exception class
class Matherr {
    public:
        Matherr() {this->errname = "Math Error.";}
        string getName() const {return this->errname;}
	void setName(string name) {this->errname = name;}
    private: 
        string errname; 
};

class DivideByZero : public Matherr
{
    public:
        DivideByZero() {setName("Division by zero");}
};
 
double divide(int a, int b) {
    if(b == 0)
        throw DivideByZero();
    return (double) a / b;
}
 
int main() {
       double d = divide(4, 0);
       cout << d << endl;
       return 0;
}
