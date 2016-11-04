/* 
 * File:   SortingList.h
 * Purpose: provide the declaration of the class SortingList
 * Author: pike
 *
 */

#ifndef SORTINGLIST_H
#define	SORTINGLIST_H

#include <iostream>
#include "Country.h"

using namespace std;

const int INITIAL_CAPACITY = 5;

class SortingList
{
  public:
    SortingList();            // default constructor, set up the capacity = INITIAL_CAPACITY
    SortingList(int incapacity);  // constructor, set up the capacity = incapacity
    SortingList(const SortingList &other);  // copy constructor
    ~SortingList();
    void insertAtTail(Country item);     // insert a new item at the tail of the list
    int GetSize() const { return size; }
    Country &Element(int x);        // return reference to an element at index of x
    void print() const; 
    // apply bubble_sort algorithm to the elements in the list
    // pass in function name as the parameter
    // passed in function defines the comparison between two elements 
    void bubble_sort(int (*compare)(Country C1, Country C2));
    SortingList &operator=(const SortingList &other);   // assignment operator overloading

  private:
    int capacity;       // the capacity of the dynamic array(list)
    int size;           // the total number of elements in the list
	Country *p;         // pointer pointing to the first element in the list
};


#endif	/* SORTINGLIST_H */

