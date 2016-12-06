#include <iostream>
#include <string>
#include "autocomplete.h"
#include "term.h"

using namespace std;

// default constructor
Autocomplete::Autocomplete(){}

// insert in item into the terms vector
void Autocomplete::insert(Term t){
  terms.push_back(t);
}

/*
  function: allMatches()
  inputs:
    - a string prefix to match with
    - a vector passed by reference to fill with matching terms
  purpose:
    - find all terms that match the given prefix
    - this assumes that the terms have already been lexographically sorted
  the general algorithm:
    - use binary search to find an index that has a matching key
    - scan in both directions from the mathcing index until terms don't match the prefix
    - push all terms within the starting and ending index into the matches vector (passed by reference)
*/
void Autocomplete::allMatches(string prefix, vector<Term> &matches){
  int a, b, bs_retval, starting_pos = 0, ending_pos = terms.size();
  a = 0;
  b = terms.size()-1;

  // binary search
  bs_retval = binarySearch(prefix, a, b);

  // check what was found
  if (bs_retval == -1){
    cout << "No mathes found\n";
  }
  else if (bs_retval == 1){
    // scan in both directions until keys no longer match
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
    // push terms to matches vector
    for (int i = starting_pos; i < ending_pos+1; i++){
      matches.push_back(terms[i]);
    }
  }
  else if (bs_retval == 2){
    // scan in both directions until keys no longer match
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
    // push terms to matches vector
    for (int i = starting_pos; i < ending_pos+1; i++){
      matches.push_back(terms[i]);
    }
  }
  else { // case where there was some sort of error
    cout << "Some sort of error in binary search\n";
  }
}

/*
  this algorithm runs in O(logn) time
*/
int Autocomplete::binarySearch(string key, int &first, int &last){

  if (terms[first].prefixMatch(key)){ // case where the term at the "first" index matches
    return 1;
  }
  else if (terms[last].prefixMatch(key)){ // case where the term at the "last" index matches
    return 2;
  }

  if (last - first <= 1){ // case where there were no matching terms found
    return -1;
  }

  int middle = last - (last-first)/2; // get the middle index
  if (key < terms[middle].getKey()){
    last = middle;
    return binarySearch(key, first, last); // recursively call binarySearch
  }
  else {
    first = middle;
    return binarySearch(key, first, last); // recursively call binarySearch
  }

  return 0;

}

/*
  this algorithm runs in O(n^2) times
*/
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

// print all the terms
void Autocomplete::print(){
  for (int i = 0; i < terms.size(); i++){
    cout << terms[i].getWeight() << ":    " << terms[i].getKey() << endl;
  }
}
