/* 
 * File:   converter.h
 * Author: Pike
 *
 */

#ifndef CONVERTER_H
#define	CONVERTER_H

#include <string>
using namespace std;

const int HIGHPRECEDENCE = 2;
const int LOWPRECEDENCE = 1;

bool isOperand(char op);
int precedence(char op);
string infix_to_postfix(string infix_exp);
bool valid_parentheses(string infix_exp);

#endif	/* CONVERTER_H */

