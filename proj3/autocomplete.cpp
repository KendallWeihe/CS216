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
  int a, b, bs_retval, starting_pos = 0, ending_pos = terms.size();
  a = 0;
  b = terms.size()-1;
  bs_retval = binarySearch(prefix, a, b);
  if (bs_retval < 0){
    cout << "No mathes found\n";
  }
  else if (bs_retval == 1){
    for (int i = a; i > -1; i--){
      if (!terms[i].prefixMatch(prefix)){
        starting_pos = i+1;
        break;
      }
    }
    for (int i = a; i < terms.size(); i++){
      if (!terms[i].prefixMatch(prefix)){
        ending_pos = i-1;
        break;
      }
    }
    for (int i = starting_pos; i < ending_pos+1; i++){
      matches.push_back(terms[i]);
    }
  }
  else if (bs_retval == 2){
    for (int i = b; i > -1; i--){
      if (!terms[i].prefixMatch(prefix)){
        starting_pos = i+1;
        break;
      }
    }
    for (int i = b; i < terms.size(); i++){
      if (!terms[i].prefixMatch(prefix)){
        ending_pos = i-1;
        break;
      }
    }
    for (int i = starting_pos; i < ending_pos+1; i++){
      matches.push_back(terms[i]);
    }
  }
  else {
    cout << "Some sort of error in binary search\n";
  }
}

int Autocomplete::binarySearch(string key, int &first, int &last){

  if (terms[first].prefixMatch(key)){
    return 1;
  }
  else if (terms[last].prefixMatch(key)){
    return 2;
  }

  if (last - first <= 1){
    return -1;
  }

  int middle = last - (last-first)/2;
  if (key < terms[middle].getKey()){
    last = middle;
    return binarySearch(key, first, last);
  }
  else {
    first = middle;
    return binarySearch(key, first, last);
  }

  return 0;

}

void Autocomplete::bubbleSort(){
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
