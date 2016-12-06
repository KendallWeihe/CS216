#ifndef POKEMON_CPP
#define	POKEMON_CPP

/*
 * File: Pokemon.cpp
 * Purpose: Provide the definiton of the class named Pokemon
 * Author: (your name)
 */
#include "Pokemon.h"

Pokemon::Pokemon()
{
    weight = 0;
}

Pokemon::Pokemon(long weight, string name)
{
    if (weight < 0)
    {
        cout << "Invalid Popularity! Reset to 0." << endl;
        weight = 0;
    }
    else
        this->weight = weight;
    this->name = name;
}

long Pokemon::get_weight() const
{
    return weight;
}

string Pokemon::get_name() const
{
    return name;
}

// ------------------------------------------------  
//     my implementations
// ------------------------------------------------

/*
  overload the greater than operator
  comparison is based on the pokemons name
*/
bool operator>(Pokemon pok1, Pokemon pok2){
    if (pok1.name > pok2.name)
      return true;
    else
      return false;
}

/*
  overload the output operator
*/
ostream &operator<<(ostream &out, const Pokemon &pok){
  cout << "name:    " << pok.name << "  Popularity:   " << pok.weight << endl;
  return cout;
}

#endif
