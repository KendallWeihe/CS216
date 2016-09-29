/*
  Author: Kendall Weihe
  CS216 Fall 2016
  Lab 3
  Psuedocode
    - input data into text file
      - an array for ints and strings
      - when sorting, arrays will have to be ran in parallel
    - read user input
    - execute sort
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "pokemonList.h"

using namespace std;


pokemonList::pokemonList(){

}

int pokemonList::getSize(){
  return plist.size();
}

void pokemonList::insert(pokemon item){
  plist.push_back(item);
}

void pokemonList::sort_by_popularity(){

  for (int i = 0; i < plist.size(); i++){
    for (int j = 0; j < plist.size() - 1; j++){
      if (plist[j].weight < plist[j+1].weight){
          pokemon temp = plist[j];
          plist[j] = plist[j+1];
          plist[j+1] = temp;
      }
    }
  }

}

void pokemonList::sort_by_name(){

  for (int i = 0; i < plist.size(); i++){
    for (int j = 0; j < plist.size() - 1; j++){
      if (plist[j].name > plist[j+1].name){
        pokemon temp = plist[j];
        plist[j] = plist[j+1];
        plist[j+1] = temp;
      }
    }
  }

}

void pokemonList::shuffle(){
  for (int i = 0; i < plist.size(); i++){
    swap(plist[i], plist[rand() % plist.size()]);
  }
}

void pokemonList::print(){
  for (int i = 0; i < plist.size(); i++){
    cout << plist[i].weight << "\t" << plist[i].name << endl;
  }
}

pokemonList::~pokemonList(){

}
