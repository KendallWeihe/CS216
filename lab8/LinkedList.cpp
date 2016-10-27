//LinkedList.cpp
#include <iostream>
#include "LinkedList.h"

using namespace std;

Node* LinkedList::getHead() const
{
	return head;
}

void LinkedList::insertAtFront(char item)
{
   Node* newNode = new Node(item,NULL);
   newNode->next = head;
   head = newNode;
}

char LinkedList::deleteAtFront() throw(bound_err)
{
	bound_err err("delete from empty list.");
	if (head == NULL) 
	{
       		throw err;
        	return '\0';
  	}
  	Node *ptr = head;
	char data = head->data;
  	head = head->next;
  	delete ptr;
}

void LinkedList::deleteItem(char item)
{
   Node* delPtr;
   Node* currPtr;

   //Treat the first node as a special case... head needs to be updated
   if (head->data == item)
   {
      delPtr = head;
      head = head->next;
   }
   else
   {
      currPtr = head;
      //Look for the node to be deleted
      while (currPtr->next != NULL && currPtr->next->data != item)
      {
	 currPtr = currPtr->next;
      }
      if (currPtr->next == NULL)
      {
	cout << "The element to be deleted is not in the list!" << endl;
	return;
      }
      else
      {
      	//Save its location
      	delPtr = currPtr->next;

      	//Route the list around the node to be deleted
      	currPtr->next = delPtr->next;
      }
   }

   //Delete the node
   delete delPtr;
}


void LinkedList::printList() const
{
   Node* currPtr;
   currPtr = head;

   while (currPtr != NULL)
   {
      cout << currPtr->data << endl;
      currPtr = currPtr->next;
   }
}

LinkedList::~LinkedList()
{
    while (head != NULL)
        char tmp = deleteAtFront();
}
