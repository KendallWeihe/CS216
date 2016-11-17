//course: CS216-00x
//Project: Lab Assignment 11
//Date: 11/16/2016
//Purpose: to apply bubble sorting algorithm to different types of objects 
//         and maintain a list of objects in "non-decreasing" order defined by each class.
//         
//Author: (your name)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include "SortingList.h"

using namespace std;

int main(int argc, char** argv) { 
    const int MAX = 256;
    
    ifstream in_file;

    if (argc != 2)
    {
        cout << "It needs one command line argument: <input filename>!" << endl;
        return 1;
    }

    in_file.open(argv[1]);
    if (!in_file.is_open())
    {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
    }
    
    SortingList SL1;
    while (!in_file.eof())
    {
	string text;
	getline(in_file, text);
	if (text !="")
            SL1.insertAtTail(text);
    }    
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL1.Print();
    SL1.bubble_sort();
    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL1.Print();

    in_file.close(); 
   
    string item;
    srand(time(0));
    int nums = 10;          // nums: total number of random integers
    SortingList SL2(nums);
    for (int i = 0; i < nums; i++)
    {
        ostringstream oss;
        oss << (rand() % MAX);
        item = oss.str();       // convert random integers into string objects 
        SL2.insertAtTail(item);
    } 
    cout << endl;
    cout << "The sequence of objects before sorting: " <<endl;
    SL2.Print();
    SL2.bubble_sort();
    cout << endl;
    cout << "The sequence of objects after sorting: " <<endl;
    SL2.Print();    

    return 0;
}

