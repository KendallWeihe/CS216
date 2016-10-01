#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Document.h"

using namespace std;

void print_instructions();
int input_text_file(vector<string>&, char*);

/*
  main():
    Responsible for general flow of control for the program
    Inputs: number of arguments and the text file name
    Pseudocode:
      - check if there is the correct number of arguments
      - input the text from file -- input_text_file()
      - check for error in opening file
      - print the instructions -- print_instructions()
      - build the initial document
      - begin inputting user commands:
        - loop until user enters "q" or "Q"
          - read user input
          - splice into tokens
          - check for wrong number of tokens
          - large if/else statement for each type of command
      - once user chooses to quit
        - ask the user if they would like to save file
        - if YES then save file
      - return to OS
*/
int main(int argc,char *argv[]){

  if (argc != 2) { // case where user entered wrong arugments
    cout << "Argument error" << endl;
    cout << "Usage: ./proj1 <filename>" << endl;
    return 0;
  }

  // input user file
  vector<string> document_lines;
  int check_read_return; // checks for error in opening file
  check_read_return = input_text_file(document_lines, argv[1]); // input document
  if (check_read_return < 0){ // case where there was an error in opening the file
    cout << "There was an error in opening your file, please try again" << endl;
    return -1;
  }

  // print instructions
  print_instructions();

  // build linked list
  Document document;
  if (document_lines.size() > 0){ // check if the file is empty
    for (int i=0; i<document_lines.size(); i++){
      document.insert_line(document_lines[i], i);
    }
  }
  else {
    cout << "This is an empty file\n";
  }

  // begin user editing
  string user_command = "";
  cout << "> ";
  getline(cin, user_command);
  while (1){

    vector<string> input_spliced;
    string temp;
    stringstream token (user_command); // splice command into tokens
    while (token >> temp){
      input_spliced.push_back(temp);
    }

    if (input_spliced.size() > 2){ // case where the user entered an invalid command
      cout << "This is an invalid command, please see instructions" << endl;
    }
    else { // case where user entered the correct type of command
      if ((input_spliced[0] == "i" || input_spliced[0] == "I") && input_spliced.size() == 1){ // case where the user chose to insert a line at the end of the document
        cout << "> ";
        string line;
        getline(cin, line); // read in new line
        int line_count = document.get_num_lines(); // get size of document -- user as parameter to insert_line() method
        document.insert_line(line, line_count+1); // insert the line
      }
      else if ((input_spliced[0] == "i" || input_spliced[0] == "I") && input_spliced.size() == 2){ // case where user chose to insert a line not at the end of the document
        int line_number = stoi(input_spliced[1]); // convert line number to int
        if (line_number > 0){ // case where the line number exists
          if (line_number < document.get_num_lines()){ // due to potential padding (line number > eof), anything less than the end of the file must be decremented
            line_number -= 1;
          }
          cout << "> ";
          string line;
          getline(cin, line); // read line
          document.insert_line(line, line_number);
        }
        else { // case where the user tried to enter a line number that does not exist
          cout << "This line number does not exist\n";
        }
      }
      else if ((input_spliced[0] == "d" || input_spliced[0] == "D") && input_spliced.size() == 2){ // case where user wants to delete line
        int line_number = stoi(input_spliced[1]); // convert line number to int
        document.delete_line(line_number);
      }
      else if (input_spliced[0] == "l" || input_spliced[0] == "L"){ // case where user wants to print
        document.print_document();
      }
      else if (input_spliced[0] == "s" || input_spliced[0] == "S"){ // case where user wants to save
        document.save_document(argv[1]);
      }
      else if (input_spliced[0] == "h" || input_spliced[0] == "H"){ // case where user wants to print the instructions again
        print_instructions();
      }
      else if (input_spliced[0] == "q" || input_spliced[0] == "Q") { // case where user wants to quit
        break;
      }
      else {
        cout << "Invalid command!\n";
      }
    }

    cout << "> ";
    getline(cin, user_command);

  }

  cout << "Do you want to save the changes? (Y-yes; N-np)\n";
  string save_choice;
  getline(cin, save_choice);
  if (save_choice == "Y" || save_choice == "y"){ // case where user wants to save the changes
    document.save_document(argv[1]);
  }
  cout << "Thank you for using my Editor!\n";

  return 0;

}

/*
  print_instructions():
    responsible for printing instructions to user
*/
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

/*
  input_text_file():
    responsible for inputting the text file into a vector of strings
    must check for error in opening file
*/
int input_text_file(vector<string> &document_lines, char *filename){

  ifstream text_file(filename); // open input stream
  if (!text_file){ // check for opening error
    cout << "Error in opening file" << endl;
    return -1;
  }

  string line;
  while (getline(text_file, line)){ // read line by line and append to document vector
    document_lines.push_back(line);
  }

  return 0;

}
