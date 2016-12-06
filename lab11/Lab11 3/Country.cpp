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

// ------------------------------------------------
//     my implementations
// ------------------------------------------------

/*
  overload the greater than operator
  comparison is based on the country population
*/
bool operator>(Country C1, Country C2){
  if (C1.population > C2.population)
    return true;
  else 
    return false;
}

/*
  overload the output operator
*/
ostream &operator<<(ostream &out, const Country &C){
    cout << C.name << "  (" << C.population << " : " << C.area << ")\n";
    return cout;
}

#endif
