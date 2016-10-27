//course: CS216-00x
//Project: Lab Assignment 8
//Date: 10/25/2016
//Purpose: to implement conversion tool from infix expression to postfix expression
//         using stack as the ADT
//         
//Author: (your name)

#include <iostream>
#include "converter.h"
#include "bound_err.h"

using namespace std;

int main() {
    while(true)
    {
        cout << "Infix to Postfix conversion (Enter \"Q\" or \"q\" to quit): " << endl;
        cout << "Enter an infix expression: " << endl;
        string infix_exp;
        getline(cin,infix_exp);

        if (infix_exp == "Q" || infix_exp == "q")
            break;

        try {
            if (valid_parentheses(infix_exp))
            {    
                string postfix_exp = infix_to_postfix(infix_exp);
                cout << "The postfix expression is: " << postfix_exp << endl;
            }
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

    cout << "Thank you for using the Infix to Postfix conversion tool!" << endl;
    return 0;
}
