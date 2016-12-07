/*
  Author: Kendall Weihe
  Prefix matching program
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "autocomplete.h"
#include "term.h"
#include <ctime>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){

  if (argc != 3){ // check to see if user sent in correct arguments
    cout << "Usage: ./CS216PA3 <filename> <k>\n";
    cout << "Where k = maximum number of matching elements\n";
    exit(0);
  }

  // open, read, and close file
  ifstream file;
  file.open(argv[1]);
  if (file.fail()){
    cout << "Error in opening file\n";
    exit(0);
  }
  int temp_weight;
  string temp_key;
  Autocomplete auto_complete; // define auto_complete object
  while (file >> temp_weight){ // begin reading file
    getline(file, temp_key); // key can include everything but newlines
    temp_key = temp_key.substr(1, temp_key.length());
    Term t(temp_key, temp_weight);
    auto_complete.insert(t);
  }
  file.close();

  // sort the terms
  clock_t begin, end;
  begin = clock();
  auto_complete.bubbleSort();
  end = clock();
  cout << "Time for sorting all terms: " << double(end - begin) << " clock cycles" << endl;

  // begin taking user inputs and finding matches
  string user_input = "";
  vector<Term> matching_terms;
  cout << "Please input the search query (type 'exit' to quit):\n";
  getline(cin, user_input); // read user input
  while (user_input != "exit"){ // loop until user enters exit

    // find all matches
    begin = clock();
    auto_complete.allMatches(user_input, matching_terms);
    end = clock();
    cout << "Time for searching all matched terms: " << double(end - begin) << " clock cycles" << endl;

    // use bubble sort to sort the matching terms by weight
    for (int i = 0; i < matching_terms.size(); i++){
      for (int j = 0; j < matching_terms.size()-1; j++){
        if (matching_terms[j].byWeight(matching_terms[j+1]) == 1){
          Term temp = matching_terms[j];
          matching_terms[j] = matching_terms[j+1];
          matching_terms[j+1] = temp;
        }
      }
    }

    // print the terms -- check if the number found is less than k specified in the arguments
    int num_items;
    num_items = (matching_terms.size() < stoi(argv[2])) ? matching_terms.size() : stoi(argv[2]);
    for (int i = 0; i < num_items; i++){
      matching_terms[i].print();
    }

    // empty the matching vector
    matching_terms.clear();

    cout << "Please input the search query (type 'exit' to quit):\n";
    getline(cin, user_input);
  }

  return 0;

}
