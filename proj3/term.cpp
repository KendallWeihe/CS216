#include <iostream>
#include <vector>
#include <string>
#include "term.h"

using namespace std;

// default constructor
Term::Term(){}

Term::Term(string query, int weight_p){
  key = query;
  weight = weight_p;
}

// function to get the weight
int Term::getWeight(){
  return weight;
}

// function to get the key
string Term::getKey(){
  return key;
}

// function to compare Term's lexographically
int Term::lexographic(Term that){
  if (key == that.getKey()){
    return 0;
  }
  else if (key < that.getKey()){
    return 1;
  }
  else {
    return -1;
  }
}

// function to compare Term's by weight in descending order
int Term::byWeight(Term that){
  if (weight == that.getWeight()){
    return 0;
  }
  else if (weight < that.getWeight()){
    return 1;
  }
  else {
    return -1;
  }
}

// function to compare Term's by the first r chars
int Term::byPrefix(Term that, int r){
  string key1, key2;
  for (int i = 0; i < r; i++){
    key1 = key[i];
    key2 = that.getKey()[i];
  }
  if (key1 == key2){
    return 0;
  }
  else if (key1 < key2){
    return 1;
  }
  else {
    return -1;
  }
}

// function to return true or false whether or not the Term matches the prefix
bool Term::prefixMatch(string prefix){
  string temp_prefix;
  for (int i = 0; i < prefix.length(); i++){
    temp_prefix += key[i];
  }
  if (temp_prefix == prefix){
    return true;
  }
  return false;
}

// function to print the Term
void Term::print(){
  cout << weight << ":    " << key << endl;
}
