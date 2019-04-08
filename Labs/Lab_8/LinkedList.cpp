#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

//Adds a new square to the end of the list
//@param = passes user input in a square
void LinkedList::add(Square s)
{
    Node *newNode = new Node;
    newNode->data = s;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        Node *n = first;
        while (n->next != NULL)
        {
            n = n->next;
        }
        n->next = newNode;
    }
}

//Goes through linked list to get the size of the list
//@return = returns the size of the LinkedList
int LinkedList::size() 
{ 
    Node *n = first; 
    int count = 0; 
    while (n != NULL) 
    { 
        n = n->next; count++; 
    }
    return count; 
}

//Displays elements of LinkedList
void LinkedList::print() 
{ 
    Node *n = first; 
    while (n != NULL) 
    { 
        cout << n->data << ""; 
        n = n->next; 
    }
    cout << endl; 
}

//Goes through LinkedList to get value of target data
//@param = passes in an integer for the index
//@return = returns value of target data
Square LinkedList::get(int i) 
{ 
    if (i >= 0 && i < size()) 
    { 
        Node *n = first; 
        for (int j = 0; j < i; j++) 
        { 
            n = n->next; 
        }
        return n->data; 
    }
    return Square(); 
}

//Goes through list and sets the data to input value
//@param i = passes in integer i for the index
//@param s = passes in a user input s (square)
void LinkedList::set(int i, Square s) 
{
    if (i >= 0 && i < size()) 
    {
        Node *n = first;
        for (int j = 0; j < i; j++ ) 
        {
            n = n->next; 
        }
        n->data = s;
    }
}

//Default destructor for the LinkedList to delete the create pointers
LinkedList::~LinkedList() 
{ 
    Node *nextNode; 
    Node *nodePtr = first; 
    while (nodePtr != NULL) 
    { 
        nextNode = nodePtr->next; 
        delete nodePtr; 
        nodePtr = nextNode; 
    } 
}

//Goes through LinkedList to find input square s
//@param s = target square
//@return = returns index of the first time the square is found
//otherwise returns -1 if the square is not found
int LinkedList::find(Square &s)
{
    Node *currentNode = first;
    int index = 0;
    while(currentNode)
    {
        if (currentNode->data == s)
        {
            return index;
        }
        index++;
        currentNode = currentNode->next;
    }
    return -1;
}