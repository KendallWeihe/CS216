#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// #include "DocumentList.h"

using namespace std;
const int MAX_LINE_NUM = 1000;

void print_instructions();
int input_text_file(string);

int main(int argc,char *argv[]){

  // print instructions
  print_instructions();

  // input user file
  vector<string> document_lines;
  int check_read_error;
  check_read_error = input_text_file(document_lines);

  // begin user editing

  string user_command = "";

  getline(cin, user_command);
  while (user_command.compare("Q") != 0 || user_command.compare("q") != 0){



  }

}

void print_instructions(){

  cout << "-----------------------------------------------------------" << endl;
  cout << "Welcome to my text editor." << endl;
  cout << "To insert text at the end of the file, type 'I' followed by the text." << endl;
  cout << "To insert text at a certain line number, type 'I' followed by a space and the desired line number." << endl;
  cout << "To delete a line, type 'D' followed by a space and the line number." << endl;
  cout << "To print all the lines, type 'L' and press enter." << endl;
  cout << "To save the current content, type 'S' and press enter." << endl;
  cout << "To display this introduction, type 'H' and press enter." << endl;
  cout << "To quit, type 'Q' and press enter." << endl;
  cout << "-----------------------------------------------------------" << endl;

}

int input_text_file(vector<string> &document_lines){

  ifstream text_file(argv[1]);
  if (!text_file){
    cout << "Error in opening file" << endl;
    return -1;
  }

  string line;
  while (getline(text_file, line)){
    document_lines.push_back(line);
  }

}
