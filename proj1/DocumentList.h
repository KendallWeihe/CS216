#ifndef DOCUMENTLIST_H
#define	DOCUMENTLIST_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class DocumentList;

class Document {

  private:
    string line;
    Document *next_node;

  public:
    Document(string, Document*);
    string get_line() const;
    Document const* get_next_node();

    friend DocumentList;

};

class DocumentList {

  private:
    Document *head;

  public:
    DocumentList(){ head=NULL; };
    int get_num_lines();
    void insert_line(string, int);
    void delete_line(int);
    void print_document();
    void save_document(string);

};

#endif
