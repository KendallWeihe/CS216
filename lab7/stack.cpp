#include <iostream>
#include "stack.h"
#include "bound_err.h"

void stack::push(char item) throw(bound_err){
  if (isFull()){
    cout << "Stack is already full" << endl;
  }
  else {
    top++;
    data[top] = item;
  }
}

char stack::pop() throw(bound_err){
  if (isEmpty()){
    cout << "Stack is empty" << endl;
    return ' ';
  }
  else {
    char item;
    item = data[top];
    top--;
    return item;
  }
}

bool stack::isFull() const{
  if (top == 4){
    return true;
  }
  return false;
}

bool stack::isEmpty() const{
  if (top == -1){
    return true;
  }
  return false;
}
