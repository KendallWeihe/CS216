#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Term {
  public:
    Term();
    Term(string query, int weight_p);
    int getWeight();
    string getKey();
    int byWeight(Term that);
    int lexographic(Term that);
    int byPrefix(Term that, int r);
    bool prefixMatch(string prefix);
    void print();
  private:
    string key;
    int weight;
};

#endif
