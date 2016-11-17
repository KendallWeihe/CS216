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

#endif
