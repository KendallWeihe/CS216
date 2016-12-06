/*
 * file: Pokemon.h
 * Purpose: provide the declaration of the class named Pokemon
 * Author: <your name>
 *
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pokemon
{
   public:
    Pokemon();   //default constructor
    Pokemon(long weight, string name);
    long get_weight() const;
    string get_name() const;
    friend bool operator>(Pokemon pok1, Pokemon pok2);
    friend ostream &operator<<(ostream &out, const Pokemon &pok);

   private:
    long weight;   // the popularity of the pokemon character
    string name;   // the name of the pokemon character
};


#endif  /* POKEMON_H */

#include "SortingList.cpp"
