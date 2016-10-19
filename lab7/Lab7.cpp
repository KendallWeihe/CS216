//course: CS216-00x
//Project: Lab Assignment 7
//Date: 10/18/2016
//Purpose: to implement the check for matched parentheses using F-I-L-O feature of stack
//         
//Author: (your name)

#include <iostream>
#include <string>
#include "stack.h"
#include "bound_err.h"

using namespace std;

bool valid_parentheses(string exp);

int main() {
    while(true)
    {
        cout << "Enter an expression: ";
        string expression;
        getline(cin, expression);

        if (expression == "Q" || expression == "q")
            break;
        try {
            if (valid_parentheses(expression))
                cout << "Parsing parentheses: Matched!" << endl;
            else
                cout << "Parsing parentheses: Unmatched!" << endl;
        } catch (bound_err &err) {
                cout << "Error: Bounds exceeded" << endl;
                cout << "Reason: " << err.get_what() << endl;
          }
          catch (...) {
                cout << "Error: Unexpected exception occurred" << endl;
          }
    }
    cout << "Thank you for using this program." << endl;
    return 0;
}

bool valid_parentheses(string E)
{
    stack S;
    for(int i = 0; i < E.length(); i++)
    {
	if (E[i] == '(')
            S.push(E[i]);
	if (E[i] == ')')
            S.pop();
    }	
    return S.isEmpty();
}

