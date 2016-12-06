#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "autocomplete.h"
#include "term.h"

using namespace std;

int main(int argc, char *argv[]){
  // TODO
    // open file
    // read into vector
    // close file
    //
    // sort the vectors
    //   what are the vectors?

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
  auto_complete.print();
  cout << endl;

  string user_input = "";
  vector<Term> matching_terms;
  while (user_input != "exit"){
    cout << "Please input the search query (type 'exit' to quit):\n";
    cin >> user_input;

    auto_complete.allMatches(user_input, matching_terms);

    for (int i = 0; i < matching_terms.size(); i++){
      matching_terms[i].print();
    }

    matching_terms.clear();
  }

}
