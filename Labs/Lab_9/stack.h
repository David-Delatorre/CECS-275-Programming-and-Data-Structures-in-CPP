#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Point.cpp"
using namespace std; 


class Stack 
{
private:
	
	struct Node 
	{
		Point value;//value of the point
		Node *next;//points to the next node
	}; 
	Node *top; //points to the node on the top of the stack
	
public:
	Stack() 
	{ 
		top = NULL; 
	}

	~Stack(); 

	bool isEmpty() 
	{ 
		return top == NULL; 
	}
	void push(Point); 
	Point pop(); 
	Point peek() 

	{ 
		return top->value; 
	}

	int size(); 
	void printStack(); 
};
#endif
