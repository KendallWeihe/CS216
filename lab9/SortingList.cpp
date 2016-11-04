/* 
 * File:   SortingList.cpp
 * Purpose: provide the implementation of the member functions of the class SortingList
 * Author: pike
 *
 */
#include <cassert>
#include "Country.h"
#include "SortingList.h"

SortingList::SortingList()
{
    capacity = INITIAL_CAPACITY;
    size = 0;
    p = new Country[capacity];	// create a dynamic array of string objects
    assert(p != NULL);
}

SortingList::SortingList(int incapacity)
{
	assert(incapacity > 0);
        capacity = incapacity;
    p = new Country[capacity];	// create a dynamic array of string objects
    assert(p != NULL);
    size = 0;
}

SortingList::SortingList(const SortingList &other) : capacity(other.capacity), size(other.size)
{
    p = new Country[capacity];    // create array of base type objects
    assert(p != 0);
    for (int i = 0; i < size; i++)
    {
        p[i] = other.p[i];
    }
}

SortingList::~SortingList()
{
    delete[] p;	// release the dynamic array
}


void SortingList::insertAtTail(Country item)
{
    size = size + 1;
    if (size >= capacity) 
    {
        // No more room:  allocate more.
        capacity *= 2;
        Country* copy = new Country[capacity];
        assert(copy != NULL);
        // Copy over the data
        for (int i = 0; i < size; i++)
            copy[i] = p[i];
        // Free the old copy and point to the new one.
        delete[] p;
        p = copy;
    }
    // insert at the back of the list
    // Note that the size has been increased one at the beginning
    // size represents the size after inserting the new item
    p[size-1] = item;   
}

Country &SortingList::Element(int x)
{
    assert(x >= 0 && x < size);
    return p[x];
}

void SortingList::print() const
{
    for (int x = 0; x < size; x++)
    {
        cout << p[x] << endl;
    }
}

SortingList &SortingList::operator=(const SortingList &other)
{
    if (this != &other)
    {
        assert(size == other.size);
        for (int i = 0; i < size; i++)
            p[i] = other.p[i];
    }
    return *this;
}

void SortingList::bubble_sort(int (*compare)(Country C1, Country C2))
{
    Country temp;   // for swapping
    for (int i = 0 ; i < size-1 ; i++)
    {
        for (int j = 0 ; j < size-1 ; j++)
        {
            if ( (*compare)(p[j], p[j + 1]) >0 )
	        {
                temp = p[j];
		        p[j] = p[j+1];
		        p[j+1] = temp;
            }        
        }
    }
}    

