/*
 * File:   SortingList.h
 * Purpose: to provide the declaration of the class named SortingList
 *          it stores a sequence of objects to perform sorting operation
 * Author: <your name>
 *
 */

#ifndef SORTINGLIST_H
#define	SORTINGLIST_H

#include <iostream>
#include <string>

using namespace std;

const int INITIAL_CAPACITY = 5;

template<class T>
class SortingList
{
  public:
    SortingList();            // default constructor, set up the capacity = INITIAL_CAPACITY
    SortingList(int incapacity);  // constructor, set up the capacity = incapacity
    SortingList(const SortingList &other);  // copy constructor
    ~SortingList();
    void insertAtTail(T item);     // insert a new item at the tail of the list
    int GetSize() const { return size; }
    T &Element(int x);        // return reference to an element at index of x
    void Print() const;
    void bubble_sort();         // apply bubble_sort algorithm to the elements in the list
    SortingList &operator=(const SortingList &other);   // assignment operator overloading

  private:
    int capacity;       // the capacity of the dynamic array(list)
    int size;           // the total number of elements in the list
    T *p;          // pointer pointing to the first element in the list
};


#endif	/* SORTINGLIST_H */

#include "SortingList.cpp"
