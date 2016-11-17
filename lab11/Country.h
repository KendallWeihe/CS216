/*
 * File:   Country.h
 * Purpose: provide the declaration of the class Country
 * Author: <your name>
 *
 */

#ifndef COUNTRY_H
#define	COUNTRY_H

#include <iostream>
#include <string>

using namespace std;

class Country
{
  public:
    Country();
    Country(string n, long p, double a);
    string get_name() const;
    long get_population() const;
    double get_area() const;
    friend bool operator>(Country C1, Country C2);
    friend ostream &operator<<(ostream &out, const Country &C);

  private:
    string name;
    long population;
    double area;    // square kilometers
};

#endif	/* COUNTRY_H */

#include "SortingList.cpp"
