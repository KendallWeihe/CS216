//converter.cpp

#include <iostream>
#include "converter.h"
#include "stack.h"
#include <string>

bool isOperand(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '(' || op == ')')
        return false;
    return true;
}

int precedence(char op)
{
    if (op == '*' || op == '/')
        return HIGHPRECEDENCE;
    if (op == '+' || op == '-')
        return LOWPRECEDENCE;
    return -1;
}

string infix_to_postfix(string Ei)
{
    stack S;
    string Eo = "";
    for (int i = 0; i < Ei.length(); i++){ // iterate over string
      if (isOperand(Ei[i])){ // if operand, then append to output string
        Eo += Ei[i]; // append / concatenate
      }
      else if (Ei[i] == '('){
        S.push(Ei[i]); // if opening parentheses then push to stack
      }
      else if (Ei[i] == ')'){ // is closing parentheses, then pop and append everything from stack until (
        char top_element = S.peek();
        while (top_element != '('){ // loop until (
          Eo += top_element;
          S.pop();
          top_element = S.peek();
        }
        S.pop(); // pop off (
      }
      else {
        if (S.isEmpty()){ // if the stack is empty then just push operator
          S.push(Ei[i]);
        }
        else {
          char top_element = S.peek(); // look at top element on stack
          if (precedence(Ei[i]) > precedence(top_element)){
            S.push(Ei[i]); // if the operator is of greater precendence
          }
          else { // else the operator is of lesser or equal precedence
            while (precedence(Ei[i]) <= precedence(top_element) && !S.isEmpty()){ // pop and append until a greater precedence operator or an empty stack
              top_element = S.peek();
              Eo += top_element; // append to output
              S.pop();
            }
            S.push(Ei[i]); // push the lower precedence operator onto the stack
          }
        }
      }
    }

    char top_element;
    while (!S.isEmpty()){ // pop and append until the stack is empty
      top_element = S.peek();
      Eo += top_element;
      S.pop();
    }

    return Eo; // return output string

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
