#include <iostream>
#include <string>
#include "autocomplete.h"
#include "term.h"

using namespace std;

Autocomplete::Autocomplete(){

}

void Autocomplete::insert(Term t){
  terms.push_back(t);
}

void Autocomplete::allMatches(string prefix, vector<Term> &matches){
  int a, b;
  a = 0;
  b = terms.size()-1;
  binarySearch(prefix, a, b);
  for (int i = a; i < b; i++){
    matches.push_back(terms[i]);
  }
}

int Autocomplete::binarySearch(string key, int &first, int &last){

  if (first >= last || last - first == 1){
    return -1;
  }

  int middle = last - (last-first)/2;
  if (terms[first].prefixMatch(key)){
    // case: the prefix matches at the first index
    for (int i = first; i > 0; i--){
      if (!terms[i].prefixMatch(key)){
        first = i+1;
        break;
      }
    }
    for (int i = first; i < terms.size()-1; i++){
      if (!terms[i].prefixMatch(key)){
        last = i-1;
        break;
      }
    }
    return 0;
  }
  else if (terms[last].prefixMatch(key)){
    // case: the prefix matches at the end index
    for (int i = last; i > 0; i--){
      if (!terms[i].prefixMatch(key)){
        first = i+1;
        break;
      }
    }
    for (int i = last; i < terms.size()-1; i++){
      if (!terms[i].prefixMatch(key)){
        last = i - 1;
        break;
      }
    }
    return 0;
  }
  else if (key < terms[middle].getKey()){
    last = middle;
    binarySearch(key, first, last);
  }
  else {
    first = middle;
    binarySearch(key, first, last);
  }

}

void Autocomplete::bubbleSort(){
  cout << terms.size() << endl;
  bool t = "Quinton Flynn" > "John Rothman";
  cout << t << endl;
  for (int i = 0; i < terms.size(); i++){
    for (int j = 0; j < terms.size()-1; j++){
      if (terms[j].getKey() > terms[j+1].getKey()){
        Term temp = terms[j];
        terms[j] = terms[j+1];
        terms[j+1] = temp;
      }
    }
  }
}

void Autocomplete::print(){
  for (int i = 0; i < terms.size(); i++){
    cout << terms[i].getWeight() << ":    " << terms[i].getKey() << endl;
  }
}
