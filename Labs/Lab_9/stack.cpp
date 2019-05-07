#include <iostream>
#include "Stack.h"

//Pushes down from the top
void Stack::push( Point val ) 
{
	Node *newNode = new Node;
	newNode->value = val;
	newNode->next = top;
	top = newNode;
}

//Removes the point at the top
//@return = the new point
Point Stack::pop() 
{
	Point retVal;
	if( top != NULL )
	{
		retVal = top->value;
		Node *temp = top->next;
		delete top;
		top = temp;
	}
	return retVal;
}

//Getse the size of the stack
//@return = size
int Stack::size() 
{
	int size = 0;
	Node *findLast = top;
	while (findLast != NULL) 
	{ 
		findLast = findLast->next; 
		size++; 
	}
	return size;
}

//Destructor
Stack::~Stack()
{ 
	Node *nextNode; 
	Node *nodePtr = top; 
	while (nodePtr != NULL) 
	{ 
		nextNode = nodePtr->next; 
		delete nodePtr; 
		nodePtr = nextNode; 
	} 
}