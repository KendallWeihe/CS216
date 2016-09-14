#ifndef POKEMONLIST_H
#define POKEMONLIST_H

#include <string>
#include <vector>
using namespace std;

class pokemon
{
   public:
  	pokemon() {weight = 0;}   //default constructor
  	pokemon(long weight, string name) {this->weight = weight; this->name = name;}
  	friend class pokemonList;
   private:
  	long weight;   // the popularity of the pokemon character
  	string name;   // the name of the pokemon character
};

class pokemonList
{
   public:
  	pokemonList(); // default constructor
  	int getSize();  //return how many pokemon characters in the list
  	void insert(pokemon item);  // insert the pokemon object item into the end of the current list
  	void sort_by_popularity();  // put all the items in the sequence in non-ascending order by popularity
  	void sort_by_name();   // put all the items in the sequence in lexicographical order by names
  	void shuffle();   //put all the items in the sequence in random order
  	void print();  // display all the items in the array
    ~pokemonList();  // destructor
   private:
  	vector<pokemon> plist;
};

#endif
