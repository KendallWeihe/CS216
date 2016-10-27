//stack.cpp

#include "stack.h"

using namespace std;

void stack::push(char item) throw(bound_err)
{
    bound_err err("Push overflows stack");
    if (isFull())
        throw err;
    LinkedStack.insertAtFront(item);
    top = LinkedStack.getHead();
}

void stack::pop() throw(bound_err)
{
    bound_err err("Pop underflows stack");
    if (isEmpty())
        throw err;
    char data = LinkedStack.deleteAtFront();
    top = LinkedStack.getHead();
}

char stack::peek() throw(bound_err)
{
    bound_err err("Peek underflows stack");
    if (isEmpty())
        throw err;
    char peekTop = top->getData();
    return peekTop;
}


bool stack::isEmpty() const
{
    if (top == NULL)
        return true;
    return false;
}

bool stack::isFull() const
{
    return false;
}

