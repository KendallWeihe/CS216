#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <iostream>
#include <vector>
#include <string>
#include "term.h"

using namespace std;

// see autocomplete.cpp for comments on functions
class Autocomplete {
  public:
    Autocomplete();
    void insert(Term t);
    void allMatches(string prefix, vector<Term> &matches);
    int binarySearch(string key, int &first, int &last);
    void bubbleSort();

    void print();

  private:
    vector<Term> terms;
};

#endif
