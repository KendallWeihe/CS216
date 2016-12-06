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

  if (argc != 3){
    cout << "Usage: ./CS216PA3 <filename> <k>\n";
    cout << "Where k = maximum number of matching elements\n";
    exit(0);
  }

  ifstream file;
  file.open(argv[1]);
  int temp_weight;
  string temp_key;
  Autocomplete auto_complete;
  while (file >> temp_weight){
    getline(file, temp_key);
    temp_key = temp_key.substr(1, temp_key.length());
    Term t(temp_key, temp_weight);
    auto_complete.insert(t);
  }
  file.close();

  clock_t begin, end;
  begin = clock();
  auto_complete.bubbleSort();
  end = clock();
  cout << "Time for sorting all terms: " << double(end - begin) / CLOCK_PER_SEC << " seconds" << endl;

  string user_input = "";
  vector<Term> matching_terms;
  cout << "Please input the search query (type 'exit' to quit):\n";
  getline(cin, user_input);
  while (user_input != "exit"){

    begin = clock();
    auto_complete.allMatches(user_input, matching_terms);
    end = clock();
    cout << "Time for searching all matched terms: " << double(end - begin) / CLOCK_PER_SEC << " seconds" << endl;

    for (int i = 0; i < matching_terms.size(); i++){
      for (int j = 0; j < matching_terms.size()-1; j++){
        if (matching_terms[j].byWeight(matching_terms[j+1]) == 1){
          Term temp = matching_terms[j];
          matching_terms[j] = matching_terms[j+1];
          matching_terms[j+1] = temp;
        }
      }
    }

    int num_items;
    num_items = (matching_terms.size() < stoi(argv[2])) ? matching_terms.size() : stoi(argv[2]);
    for (int i = 0; i < num_items; i++){
      matching_terms[i].print();
    }

    matching_terms.clear();

    cout << "Please input the search query (type 'exit' to quit):\n";
    getline(cin, user_input);
  }

}
