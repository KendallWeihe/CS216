//course: CS216-00x
//Project: Lab Assignment 3
//Date: 09/13/2016
//Purpose: Read data from an input file which passes in from command line argument
//         and sort pokemon objects
//         either (1)in non-ascending order by popularity, using the Insertion Sorting algorithm
//         or (2)in lexicographical order by names, using the Bubble Sorting algorithm;
//	   or (3)in random order, calling shuffle function.
//	   Display the sequence of objects respectively
//Author: Yi Pike

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "pokemonList.h"

using namespace std;

int main(int argc, char** argv)  {
   const int ARGUMENTS = 2;
   ifstream in_file;

   if (argc != ARGUMENTS)
   {
	cout << "It needs one command line argument: <input filename>!" << endl;
        return 1;
   }

   in_file.open(argv[1]);
   if (!in_file.good())
   {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
   }

   long weight;    // popularity of Pokemon characters
   string name;
   pokemonList myCollection;

    while (!in_file.eof())
    {
        in_file >> weight >> ws;
        getline(in_file, name);
        if (name != "")
        {    
            pokemon newterm(weight, name);
            myCollection.insert(newterm);
        }    
    } 
    in_file.close();

    string option;
    cout << "Please choose the option to sort the pokemon characters: " << endl;
    cout << "Enter p --- to sort in non-ascending order by popularity;" << endl;
    cout << "Enter n --- to sort in lexicographical(dictionary) order by names;" << endl;
    cout << "Enter r --- to sort in random order;" << endl;
    cout << "Enter q --- to quit the program;" << endl;
    getline(cin, option);
    while (option != "q" && option != "Q")
    {
	if (option == "p" || option =="P")
	{
	      if (myCollection.getSize() > 0)
	      {
    		   myCollection.sort_by_popularity();
      		   cout << "The sequence of pokemon characters in decreasing order by popularity: " <<endl;
      		   myCollection.print();      
   	       }    
	      else
		   cout << "The sequence is empty!" << endl;
	}
	else if (option == "n" || option =="N")
        {
              if (myCollection.getSize() > 0)
              {
                   myCollection.sort_by_name();
                   cout << "The sequence of pokemon characters in dictionary order by names: " <<endl;
                   myCollection.print();      
               }    
	       else
		   cout << "The sequence is empty!" << endl;
        }
        else if (option == "r" || option =="R")
        {
              if (myCollection.getSize() > 0)
              {
                   myCollection.shuffle();   // put the pokemon objects in random order
                   cout << "The sequence of pokemon characters in random order: " <<endl;
                   myCollection.print();      
               }    
               else
                   cout << "The sequence is empty!" << endl;
        }
	else
	      cout << "Invalid option, please try again..." << endl;

    	cout << "Please choose the option to sort the pokemon characters: " << endl;
    	cout << "Enter p --- to sort in non-ascending order by popularity;" << endl;
    	cout << "Enter n --- to sort in lexicographical(dictionary) order by names;" << endl;
	cout << "Enter r --- to sort in random order;" << endl;
    	cout << "Enter q --- to quit the program;" << endl;
    	getline(cin, option);
    }

    return 0;
}

