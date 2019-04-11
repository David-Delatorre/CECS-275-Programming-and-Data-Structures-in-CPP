#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "contact.h"

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

public:
    //Default constructor; sets first to null
    LinkedList();

    //Default destructor to delete created LinkedList
    ~LinkedList(); 
    
    void write(ofstream &file);
    
    //checks to see if the LinkedList is empty
    bool isEmpty() { return first == NULL; }

    //Goes through linked list and gets size of list
    //@return = size of list
    int getSize();

    //Grabs index of a contact
    //@param = index of contact in list
    //@return contact from index
    Contact getContact(int);

    //Sets a contact to set index
    //@param index = index of contact in list
    //@param con = contact to place in index chosen
    void setIndex(int index, Contact con);
    
    //adds a new contact to the end of LinkedList
    void add2End(Contact con);
    
    //Displays contents of LinkedList
    void print(); 

    //////////////Remove functions
    //
    bool removeStart();
    
    //
    bool removeLast();
    
    //remove a contact by first + last name
    //@param = first = first name
    //@param = last = last name
    //@return = if true then contact is removed, else contact not found
    bool remove(string first, string last);
    
    //Remove contact by index
    //@param = index
    //@return = if true then contact is removed, else contact not found
    bool remove(int);

    //Sorts list in alphabetical order
    void sort();

    ///////////////Search functions
    // bool search(string input);
    LinkedList *searchAs(string target, char option);
    Contact* modSearch(string first, string last);

    friend ostream& operator<<(ostream& out, LinkedList &con);
};

#endif