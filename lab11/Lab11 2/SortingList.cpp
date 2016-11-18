#ifndef SORTINGLIST_CPP
#define SORTINGLIST_CPP

/* File:   SortingList.cpp
 * Purpose: to provide the definition of the class named SortingList
 *          it stores a sequence of objects to perform sorting operation
 * Author: kendall weihe
 *
 */
#include <cassert>
#include "SortingList.h"

//NOTE notice that SortingList is a template class
template<class T>
SortingList<T>::SortingList()
{
    capacity = INITIAL_CAPACITY;
    size = 0;
    p = new T[capacity];	// create a dynamic array of T objects
    assert(p != NULL);
}

template<class T>
SortingList<T>::SortingList(int incapacity)
{
	assert(incapacity > 0);
        capacity = incapacity;
	p = new T[capacity];	// create a dynamic array of T objects
	assert(p != NULL);
        size = 0;
}

template<class T>
SortingList<T>::SortingList(const SortingList<T> &other) : capacity(other.capacity), size(other.size)
{
	p = new T[capacity];            // create array of base type objects
	assert(p != 0);
	for (int i = 0; i < size; i++)
	{
            p[i] = other.p[i];
	}
}


template<class T>
SortingList<T>::~SortingList()
{
	delete [] p;	// release the dynamic array
}


template<class T>
void SortingList<T>::insertAtTail(T item)
{
    size = size + 1;
    if (size >= capacity)
    {
        // No more room:  allocate more.
        capacity *= 2;
        T* copy = new T[capacity];
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

template<class T>
T &SortingList<T>::Element(int x)
{
	assert(x >= 0 && x < size);
	return p[x];
}

template<class T>
void SortingList<T>::Print() const
{
	for (int x = 0; x < size; x++)
	{
            cout << p[x] << endl;
	}
}

template<class T>
SortingList<T> &SortingList<T>::operator=(const SortingList<T> &other)
{
	if (this != &other)
	{
		assert(size == other.size);
		for (int i = 0; i < size; i++)
                    p[i] = other.p[i];
	}
	return *this;
}

template<class T>
void SortingList<T>::bubble_sort()
{
    T temp; //for swapping
    for (int i = 0 ; i < size-1 ; i++)
    {
        for (int j = 0 ; j < size-1 ; j++)
        {
            if ( p[j] > p[j + 1] )
            {
                temp = p[j];
                p[j]=p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

#endif
