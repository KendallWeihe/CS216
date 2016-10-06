#ifndef Document_H
#define	Document_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Document;

/*
  class Line:
    This class consist of a node that is used by the friend class Document
    Each node serves as a node in a linked list
    Each node consists of a line of type string and a pointer to the next node
*/
class Line {

  private:
    string line; // for a line of text
    Line *next_node; // pointer to the next node

  public:
    Line(string, Line*); // constructor -- constructs a single node
    friend Document; // friend relationship to Document class

};

/*
  class Document:
    This class is responsible for building and maintaining a linked list -- where each node is a line of text
    This class is a friend to the Line class
    The only private data member is a pointer HEAD that points to the beginning on the linked list
    Member functions consist of:
      - get_num_lines(): returns total number of lines
      - insert_line(): inserts a line into the linked list
      - delete_line(): delete a line from the linked list
      - print_document(): prints entire linked list
      - save_document(): saves document to an output file
*/
class Document {

  private:
    Line *head; // HEAD pointer to linked list

  public:
    Document(){ head=NULL; }; // constructor -- initialize head to NULL
    int get_num_lines(); // returns number of lines
    void insert_line(string, int); // inserts a line
    void delete_line(int); // deletes a line
    void print_document(); // prints the document
    void save_document(string); // saves the document
    ~Document(){ delete head; }; // destructor

};

#endif
