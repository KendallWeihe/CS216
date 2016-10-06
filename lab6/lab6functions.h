// lab6function.h
// Provide the declaration of functions needed 

#ifndef LAB6FUNCTIONS_H
#define LAB6FUNCTIONS_H

#include <iostream> 
#include <string>
#include <list>

using namespace std;

extern int num1;
extern const int SIZE;

int* func1(int &parm1, int parm2); 
int func2(int count); 
list<string> func3();
string change_Str(string original_str); 
string reverse(string original, int& times);

#endif  //LAB6FUNCTIONS_H
