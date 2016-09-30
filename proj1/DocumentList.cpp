#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "DocumentList.h"

using namespace std;

// DOCUMENT METHODS-----------------------------------------------------------------

Document::Document(string new_line, Document *new_next_node){
  line = new_line;
  next_node = new_next_node;
}

// string Document::get_line(){
//   return line;
// }
//
// Document const* Document::get_next_node(){
//   return next_node;
// }


// DOCUMENTLIST METHODS-------------------------------------------------------------

int DocumentList::get_num_lines(){

  Document *curr_ptr = head;
  int count = 0;

  while (curr_ptr != NULL){
    count += 1;
    curr_ptr = curr_ptr->next_node;
  }

  return count;

}

void DocumentList::insert_line(string line, int line_number){

  Document *curr_ptr = head;
  Document *prev_ptr = NULL;
  Document *new_line_ptr;

  new_line_ptr = new Document(line, curr_ptr);

  if (head == NULL){ // case list empty
    head = new_line_ptr;
  }
  else {

    int line_count = 1;
    while (curr_ptr != NULL && line_count < line_number){
      prev_ptr = curr_ptr;
      curr_ptr = curr_ptr->next_node;
      line_count += 1;
    }

    if (curr_ptr == NULL){ // case where insertion is at the end of the list
      prev_ptr->next_node = new_line_ptr;
      new_line_ptr->next_node = NULL;
    }
    else if (prev_ptr == NULL){ // case where insertion is at the beginning of an existing list
      head = new_line_ptr;
      new_line_ptr->next_node = curr_ptr;
    }
    else { // case where insertion is in the middle of the list
      prev_ptr->next_node = new_line_ptr;
      new_line_ptr->next_node = curr_ptr;
    }

  }

}

void DocumentList::delete_line(int line_number){

  if (line_number > get_num_lines()){
    cout << "You are trying to delete a line that does not exist\n";
  }
  else{

      Document *curr_ptr = head;
      Document *prev_ptr = NULL;

      int line_count = 1;
      while (curr_ptr != NULL && line_count < line_number){
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr->next_node;
        line_count += 1;
      }

      prev_ptr->next_node = curr_ptr->next_node;
      delete curr_ptr;

  }

}

void DocumentList::print_document(){

  Document *curr_ptr = head;

  if (curr_ptr == NULL){
    cout << "This is an empty document\n";
  }
  else {

      int line_number = 1;
      while (curr_ptr != NULL){
        cout << line_number << "> " << curr_ptr->line << endl;
        curr_ptr = curr_ptr->next_node;
        line_number += 1;
      }

  }

}

void DocumentList::save_document(string filename){

  Document *curr_ptr = head;

  if (curr_ptr == NULL){
    cout << "This is an empty document\n";
  }
  else{

      ofstream file(filename);

      while (curr_ptr != NULL){
        file << curr_ptr->line << endl;
        curr_ptr = curr_ptr->next_node;
      }

      file.close();

  }

}
