//course: CS216-00x
//Project: Lab Assignment 9
//Date: 11/01/2016
//Purpose: to apply sorting algorithm to the objects of Country class 
//         first order: sort objects in lexicographical order by name
//         second order: sort objects in non-decreasing order by population
//         first order and second order are defined as two functions in the Country class
//         Pass in the pointer to function to bubble_sort member function of SortingList class
//         to implement sorting by first order and second order respectively
//         use operator overloading of "<<" for the Country class to send the object of Country class directly to the standard output
//Author: (your name)

#include <iostream>
#include <fstream>
#include <string>
#include "Country.h"
#include "SortingList.h"

using namespace std;

int main(int argc, char** argv) { 
    ifstream in_file;

    // Check if missing command line argument
    if (argc != 2)
    {
        cout << "It needs one command line argument: <input filename>!" << endl;
        return 1;
    }

    // Check if opening the file successfully
    in_file.open(argv[1]);
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
    }
    
    // Read data from the file and store into the SortingList object
    // Assume "good data" from the file
    SortingList countryList;
    while (!in_file.eof())
    {
        string name;
        long population;
        double area;
        in_file >> name >> population >> area; 
        if (name != "")
        {    
            Country input_cty(name, population, area);
            countryList.insertAtTail(input_cty);
        }    
    }    

    //First, display the original sequence of objects
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    countryList.print();

    // Sort the objects in lexicographical order by country names
    int (*compare)(Country C1, Country C2);
    compare = &Country::compareByName;
    countryList.bubble_sort((*compare));
    cout << endl;
    cout << "The sequence of objects after sorting by name: " <<endl;
    countryList.print();

    // Sort the objects in non-decreasing order by country population
    compare = &Country::compareByPopulation;
    countryList.bubble_sort((*compare));
    cout << endl;
    cout<< "The sequence of objects after sorting by population: " << endl;
    countryList.print();

    // close the file after finishing reading data from
    in_file.close(); 
   
    return 0;
}

