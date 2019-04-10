#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "contact.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
    struct Node
    { 
        //Creates Contact named con to be used
        Contact nCon;
        //The next node to find out what's next in LinkedList
        Node *next; 
        //The previous node
        Node *prev;
    }; 
    //Creates node for the first data value
    Node *first; 
    Node *last;
    int listSize;

    void swap(Node* left, Node* right);

public:
    //Default constructor; sets first to null
    LinkedList() 
    { 
        first = NULL; 
        last = NULL;
        listSize = 0;
    }
    
    //Default destructor to delete created LinkedList
    ~LinkedList(); 
    
    //checks to see if the LinkedList is empty
    bool isEmpty() { return first == NULL; }

    //Goes through linked list and gets size of list
    //@return = size of list
    int getSize();
    
    //adds a new contact to the end of LinkedList
    void add2End(Contact con);
    
    //Displays contents of LinkedList
    void print(); 

    bool search(string input);

    bool removeStart();
    bool removeLast();
    bool remove(string first, string last);
    bool remove(int);

    void sort();

    LinkedList *searchAs(string target, char option);
    Contact* searchAs(string first, string last);

    friend ostream& operator<<(ostream& out, LinkedList &con);
};

#endif