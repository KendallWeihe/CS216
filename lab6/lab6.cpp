//course: CS216-00x
//Project: Lab Assignment 6
//Date: 10/05/2016
//Purpose: To test the scope of variables, allocation from the heap,
//         list class and recursive functions
//Author: (your name)

#include <iostream> 
#include <string>
#include <list>
#include "lab6functions.h"

using namespace std;

// global scope program storage 
int num1 = 30;   //for test purpose only, it is not recommended to use global variable
const int SIZE = 3;

int main ( ) { 
	// function scope to stack storage
	int num2 = 20; 
	int count = 1;
	int answer; 
	int* ptr; 
	ptr = func1(num1,num2); 
	cout << "answer 1: "<< *ptr << endl; 
	cout << "answer 2: "<< num1 << endl; 
	cout << "answer 3: "<< num2 << endl;
	// heap storage is freed in the main, no memory leak:)
	delete ptr;

	while (count <= SIZE)
	{
		answer = func2(count);
		count++;
	} 
	cout << "answer 4: "<< answer << endl;
	list<string> slist = func3();
    list<string>::iterator pos = slist.begin();
	// calling the recursive function to generate palindrome
	for (pos = slist.begin(); pos != slist.end(); pos++)
	{	
		string panlindrome_original = change_Str(*pos);
		cout << "The orignial string is: " << *pos << endl;
		cout << "The palindrome based on the original string is: " << panlindrome_original << endl; 
		// calling your function to reverse all the strings 
		// stored in the array pointed by sptr
		int times = 0;
		string rev_str = reverse(*pos, times);
		string panlindrome_rev = change_Str(rev_str);
		cout << "The reversed string is: " << rev_str << " by calling function " << times << " times" << endl;
		cout << "The panlindrome based on the reversed string is: " <<  panlindrome_rev << endl; 
 	}

    return 0;
}    
// heap storage is freed by calling destructor of list class
// no memory leak.
