// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "bound_err.h"

using namespace std;

class Node
{
  private:    
   char data;
   Node* next;
    
  public:
   Node():next(NULL) {};
   Node(char ch, Node* ptr): data(ch),next(ptr) {};
   char getData() const {return data;}
   Node* getNext() const {return next;}
   friend class LinkedList;  // gives LinkedList access to private data of Node
};


class LinkedList
{
  private:
   Node* head;

  public:
   LinkedList():head(NULL) {};   
   Node* getHead() const;
   void insertAtFront(char ch);
   char deleteAtFront() throw(bound_err);
   void deleteItem(char);
   void printList() const;
   ~LinkedList();
};

#endif
