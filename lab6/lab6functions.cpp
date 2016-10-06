//Provide the function implementation 
//of each function declared in lab6functions.h
//to complete the function definition
#include "lab6functions.h"

int* func1(int &parm1,int parm2) 
{ 
	// function scope to stack storage
	cout << "Calling func1: " << endl;
	// function scope ptr in stack storage, it points to storage in the heap
	int *ptr = new int; 
	int temp = parm1;
	parm1 = (parm1 + parm2)/2;  
	if (temp > parm2)
		*ptr = temp - parm1;
	else 
		*ptr = parm2 - parm1; 
	// potential memory leak!!! it needs to be released from the caller.
	return ptr; 
} 

int func2(int count)
{ 
	// function scope to stack storage
	cout << "Calling func2: " << endl;
	// function scope but program storage
	static int sum = 0; 
	// sum retains its value between calls
	sum = sum + count;   // sum keeps value for next call
	return sum;
}

list<string> func3() {
	// function scope to stack storage
	cout << "Calling func3: " << endl;
	// Use the list class to store a sequence of strings in dictionary order
    list<string> slist;
    list<string>::iterator pos = slist.begin();
    string input;
    do
    {
        cout << "Please input a text line:" << endl;
        getline(cin, input);
        if (input == "q" || input == "Q")
            break;
        pos = slist.begin();
        while (pos != slist.end() && input > *pos)
            pos++;
        slist.insert(pos,input);
    } while (true);
    // display the string elements in the list (in dictionary order)
    cout << "The items in the list (in dictionary order):" << endl;
    for (pos = slist.begin(); pos != slist.end(); pos++)
        cout << *pos << endl;
    return slist;
} 

string change_Str(string original)
{
	cout << "Calling recursive functions: " << endl;
	if (original.length() <= 1)
		return original + original;
	string mid = change_Str(original.substr(1, original.length()-1));
	return original[0] + mid + original[0];
}

string reverse(string original, int& times)
{
	return "";
}
