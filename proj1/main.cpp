#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "DocumentList.h"

using namespace std;
const int MAX_LINE_NUM = 1000;

void print_instructions();
int input_text_file(vector<string>&, char*);

int main(int argc,char *argv[]){

  if (argc != 2) {
    cout << "Argument error" << endl;
    cout << "Usage: ./proj1 <filename>" << endl;
    return 0;
  }

  // input user file
  vector<string> document_lines;
  int check_read_return;
  check_read_return = input_text_file(document_lines, argv[1]);
  if (check_read_return < 0){
    cout << "There was an error in opening your file, please try again" << endl;
    return -1;
  }

  // print instructions
  print_instructions();

  // build linked list
  DocumentList document;
  if (document_lines.size() > 0){
    for (int i=0; i<document_lines.size(); i++){
      document.insert_line(document_lines[i], i);
    }
  }
  else {
    cout << "This is an empty file\n";
    return 0;
  }

  // begin user editing
  string user_command = "";

  cout << "> ";
  getline(cin, user_command);
  while (1){

    vector<string> input_spliced;
    string temp;
    stringstream token (user_command);
    while (token >> temp){
      input_spliced.push_back(temp);
    }

    if (input_spliced.size() > 2){
      cout << "This is an invalid command, please see instructions" << endl;
    }
    else {
      if ((input_spliced[0] == "i" || input_spliced[0] == "I") && input_spliced.size() == 1){
        cout << "> ";
        string line;
        getline(cin, line);
        int line_count = document.get_num_lines();
        document.insert_line(line, line_count+1);
      }
      else if ((input_spliced[0] == "i" || input_spliced[0] == "I") && input_spliced.size() == 2){
        int line_number = stoi(input_spliced[1]);
        if (line_number > 0){
          cout << "> ";
          string line;
          getline(cin, line);
          document.insert_line(line, line_number);
        }
        else {
          cout << "This line number does not exist\n";
        }
      }
      else if ((input_spliced[0] == "d" || input_spliced[0] == "D") && input_spliced.size() == 2){
        int line_number = stoi(input_spliced[1]);
        document.delete_line(line_number);
      }
      else if (input_spliced[0] == "l" || input_spliced[0] == "L"){
        document.print_document();
      }
      else if (input_spliced[0] == "s" || input_spliced[0] == "S"){
        document.save_document(argv[1]);
      }
      else if (input_spliced[0] == "h" || input_spliced[0] == "H"){
        print_instructions();
      }
      else if (input_spliced[0] == "q" || input_spliced[0] == "Q") {
        break;
      }
    }

    cout << "> ";
    getline(cin, user_command);

  }

  cout << "Do you want to save the changes? (Y-yes; N-np)\n";
  string save_choice;
  getline(cin, save_choice);
  if (save_choice == "Y" || save_choice == "y"){
    document.save_document(argv[1]);
  }
  cout << "Thank you for using my Editor!\n";

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

int input_text_file(vector<string> &document_lines, char *filename){

  ifstream text_file(filename);
  if (!text_file){
    cout << "Error in opening file" << endl;
    return -1;
  }

  string line;
  while (getline(text_file, line)){
    document_lines.push_back(line);
  }

  return 0;

}
