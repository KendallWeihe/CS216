#include <iostream>
#include "stack.h"
#include "bound_err.h"

/*
  function: push()
  arguments:
    - item to push onto the stack
  purpose:
    - push an item onto the stack and increment the top index
*/
void stack::push(char item) throw(bound_err){
  if (isFull()){ // case where the stack is full
    cout << "Error: Bounds exceeded" << endl;
    cout << "Reason: Push overflows stack" << endl;
  }
  else {
    top++; // increment the index of the top of the stack
    data[top] = item; // push item onto the stack
  }
}

/*
  function: pop()
  arguments: None
  purpose:
    - pop and return the top item of the stack
*/
char stack::pop() throw(bound_err){
  if (isEmpty()){ // case where the stack is empty
    cout << "Error: Bounds exceeded" << endl;
    cout << "Reason: Pop underflows stack" << endl;
    return ' ';
  }
  else {
    char item;
    item = data[top]; // pop the item off the stack
    top--; // decrement top of stack index
    return item; // return the item
  }
}

/*
  function: isFull()
  arguments: None
  purpose:
    - check if the stack is full
*/
bool stack::isFull() const{
  if (top == 4){ // the stack limit is 5 -- starts at 0
    return true;
  }
  return false;
}

/*
  function: isEmpty()
  arguments: None
  purpose:
    - check is the stack is empty
*/
bool stack::isEmpty() const{
  if (top == -1){
    return true;
  }
  return false;
}
