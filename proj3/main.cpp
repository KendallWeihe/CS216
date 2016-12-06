#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "autocomplete.h"
#include "term.h"

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

  auto_complete.bubbleSort();

  string user_input = "";
  vector<Term> matching_terms;
  while (user_input != "exit"){
    cout << "Please input the search query (type 'exit' to quit):\n";
    cin >> user_input;

    auto_complete.allMatches(user_input, matching_terms);

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
  }

}
