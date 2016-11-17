#ifndef COUNTRY_CPP
#define	COUNTRY_CPP

/*
 * File:   Country.cpp
 * Purpose; provide the implementation of the member functions for the class Country
 * Author: <your name>
 *
 */
#include "Country.h"

Country::Country()
{
    population = 0;
    area = 0;
}

Country::Country(string n, long p, double a)
{
    name = n;
    if (p < 0 || a < 0)
    {
       cout << "Invalid number! Reset to 0." << endl;
       population = 0;
       area = 0;
    }
    else
    {
        population = p;
        area = a;
    }
}

string Country::get_name() const
{
    return name;
}

long Country::get_population() const
{
    return population;
}

double Country::get_area() const
{
    return area;
}

#endif
