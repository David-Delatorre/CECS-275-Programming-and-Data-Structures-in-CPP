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
int l_size;

public:
    //Default constructor; sets first to null
    LinkedList() 
    { 
        firstN = NULL; 
        lastN = NULL;
        l_size = 0;
    }
    
    //Default destructor to delete created LinkedList
    ~LinkedList(); 
    
    //checks to see if the LinkedList is empty
    bool isEmpty() { return first == NULL; }
    
    //adds a new square to the end of LinkedList
    void add(Contact con); 
    
    //Goes through linked list and gets the size of list
    int size(); 
    
    //Displays contents of LinkedList
    void print(); 
};

#endif