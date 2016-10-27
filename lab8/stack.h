/*
 * stack class
 *
 * Member functions
 *  push-- put an item on the stack
 *  pop -- remove an item from stack
 *  isEmpty -- return true if the stack is empty; otherwise false
 *  isFull -- return true if the stack is full; otherwiese false
 */
#ifndef STACK_H
#define STACK_H

#include "bound_err.h"
#include "LinkedList.h"

class stack
{
    public:
        stack():top(NULL) {};
        //Copy constructor--use the system default;
        //Assignment operator--use the system default;

        //Push an itme on the stack
        void push(char item) throw(bound_err);

        //Pop an item from the stack
        void pop() throw(bound_err);

        //Take a look at the top item without changing the stack
        char peek() throw(bound_err);

        //Check if the stack is empty
        bool isEmpty() const;

        //Check if the stack is full, it is always false for our definition
        bool isFull() const;

    private:
        Node* top;      //the pointer points at the top item in the stack
        LinkedList LinkedStack;   //the stack is implemented on a linked list structure
};

#endif   //STACK_H
