

#include <iostream>
#include <string>
#include "Country.h"
#include "SortingList.h"

using namespace std;

Country::Country() {
  name = "";
  population = 0;
  area = 0.0;
}

Country::Country(string n, long p, double a) {
  name = n;
  population = p;
  area = a;
}

int Country::compareByName(Country C1, Country C2) {
  if (C1.name > C2.name)
    return 1;
  else
    return 0;
}

int Country::compareByPopulation(Country C1, Country C2) {
  if (C1.population > C2.population)
    return 1;
  else
    return 0;
}

ostream &operator<<(ostream &out, const Country &C) {
  return (out << C.name << "   (" << C.population << " : " << C.area << ")" << endl);
}
