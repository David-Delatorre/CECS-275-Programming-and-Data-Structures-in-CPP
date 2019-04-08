#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Square.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
struct Node
{ 
    //Creates square named "data" to be used
    Square data;
    
    //The next node to find out what's next in LinkedList
    Node *next; 
}; 
//Creates node for the first data value
Node *first; 

public:
    //Default constructor; sets first to null
    LinkedList() { first = NULL; }
    
    //Default destructor to delete created LinkedList
    ~LinkedList(); 
    
    //checks to see if the LinkedList is empty
    bool isEmpty() { return first == NULL; }
    
    //adds a new square to the end of LinkedList
    void add(Square s); 
    
    //Goes through linked list and gets the size of list
    int size(); 
    
    //Displays contents of LinkedList
    void print(); 
    
    //Goes through LinkedList to get the value of data
    Square get(int i); 
    
    //Goes through LinkedList and sets data to an input value
    void set(int i, Square s);
    
    //Goes t hrough LinkedList to find square that's input
    int find(Square &s);
};

#endif