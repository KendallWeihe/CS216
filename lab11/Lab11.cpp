//course: CS216-00x
//Project: Lab Assignment 11
//Date: 11/16/2016
//Purpose: to apply bubble sorting algorithm to different types of objects 
//         and maintain a list of objects in "non-decreasing" order defined by each class.
//         Pokemon class (from Lab3) defines the operator ">": the name in dictionary order. 
//         Country class (from Lab9) defines the operator ">": the larger population is ">" the smaller population.
//         Clock class (from Lecture slides) defines the operator ">": the later time is ">" the earlier time.
//Author: (your name)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "Pokemon.h"
#include "Country.h"
#include "Clock.h"
#include "SortingList.h"

using namespace std;

int main(int argc, char** argv) {
    
    ifstream in_file;
    string inputfile1 = "pokemon.txt";
    string inputfile2 = "countryinfo.txt";

    // open the first input file to read the data for Pokemon objects
    in_file.open(inputfile1.c_str());
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << inputfile1 << endl;	
       return 1;
    }
    
    SortingList<Pokemon> SL1;
    long weight;
    string name;
    while (in_file >> weight >> name)
    {
        Pokemon input_pok(weight,name);
        SL1.insertAtTail(input_pok);    
    }    
        
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL1.Print();
    SL1.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL1.Print();

    in_file.close(); 

    // open the second input file to read data for Country objects
    in_file.open(inputfile2.c_str());
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << inputfile2 << endl;	
       return 2;
    }
    
    SortingList<Country> SL2;
    while (!in_file.eof())
    {
    	string name;
        long population;
        double area;
        in_file >> name >> population >> area; 
        if (name != "")
        {    
            Country input_cty(name, population, area);
            SL2.insertAtTail(input_cty);
        }    
    }    
        
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL2.Print();
    SL2.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL2.Print();

    in_file.close(); 
    
    // Use random number generator to generate the data for Clock objects
    srand(time(0));
    const int MAX = 100;  
    const int NUM_CLOCK = 10; // the number of clock time in the list
    SortingList<Clock> SL3(NUM_CLOCK);
    for (int i = 0; i < NUM_CLOCK; i++)
    {
        int hours = rand() % MAX;
        int minutes = rand() % MAX;
        int seconds = rand() % MAX;
        Clock input_ck(hours, minutes, seconds);
        SL3.insertAtTail(input_ck);
    } 
    
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL3.Print();
    SL3.bubble_sort();

    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL3.Print();

    return 0;
}

