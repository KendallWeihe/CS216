#include <iostream>
#include <vector>
#include <string>
#include "term.h"

using namespace std;

Term::Term(){

}

Term::Term(string query, int weight_p){
  key = query;
  weight = weight_p;
}

int Term::getWeight(){
  return weight;
}

string Term::getKey(){
  return key;
}

int Term::byWeight(Term that){
  if (weight < that.getWeight()){
    return 0;
  }
  return -1;
}

int Term::lexographic(Term that){
  if (key < that.getKey()){
    return -1;
  }
  return 0;
}

int Term::byPrefix(Term that, int r){
  string key1, key2;
  for (int i = 0; i < r; i++){
    key1 = key[i];
    key2 = that.getKey()[i];
  }
  if (key1 < key2){
    return -1;
  }
  return 0;
}

bool Term::prefixMatch(string prefix){
  string temp_prefix;
  for (int i = 0; i < prefix.length(); i++){
    temp_prefix[i] = key[i];
  }
  if (temp_prefix == prefix){
    return true;
  }
  return false;
}

void Term::print(){
  cout << weight << ":    " << key << endl;
}
