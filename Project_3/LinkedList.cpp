#include "LinkedList.h"

/////////////////////////////////////////////////////////////////////////////////////
//Constructors/Destructors
/////////////////////////////////////////////////////////////////////////////////////
LinkedList::LinkedList() 
    { 
        first = NULL; 
        last = NULL;
        listSize = 0;
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

/////////////////////////////////////////////////////////////////////////////////////
//Other Functions
/////////////////////////////////////////////////////////////////////////////////////

//Adds a new square to the end of the list
//@param = passes user input in con object
void LinkedList::add2End(Contact con)
{
    Node *newNode = new Node;
    newNode -> nCon = con;
    newNode -> prev = last;
    newNode -> next = NULL;
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
    }

    else
    {
        last -> next = newNode;
        last = newNode;
    }
    listSize++;
}

//Goes through linked list to get the size of the list
//@return = returns the size of the LinkedList
int LinkedList::getSize() 
{ 
    Node *n = first; 
    int count = 0; 
    while (n != NULL) 
    { 
        n = n -> next; count++; 
    }
    return count; 
}

//Displays elements of LinkedList
void LinkedList::print() 
{ 
    Node *n = first; 
    while (n) 
    { 
        cout << n -> nCon << endl; 
        n = n -> next; 

    }
}

Contact LinkedList::getContact(int i)
{
	Contact con;
	if (i >= 0 && i < getSize())
	{
		Node *nNode = first;
		for (int c = 0; c < i; c++)
		{
			nNode = nNode -> next;
		}
		return nNode -> nCon;
	}
	return con;
}

/////////////////////////////////////////////////////////////////////////////////////
//REMOVE FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////////

//removing the first name 
bool LinkedList::removeStart()
{
    bool removed = false;  
	if (first != NULL) 
	{ 
		removed = true;   
		if (getSize() == 1) 
		{ 
			delete first;    
			first = NULL;    
			last = NULL; 
		} 
		else 
		{ 
			Node *tempNode = first -> next;    
			delete first;    
			first = tempNode;    
			first->prev = NULL; 
		} 
	}  
	return removed; 
}

bool LinkedList::removeLast()
{
    bool removed = false;  
	if (first != NULL) 
	{ 
		removed = true;
		if (getSize() == 1) 
		{ 
			delete first;    
			first = NULL;    
			last = NULL; 
		} 
		else 
		{ 
			Node *tempNode = last->prev;    
			delete last;    
			last = tempNode;    
			last->next = NULL; 
		} 
	}  
	
	return removed; 
}

bool LinkedList::remove(string firstN, string lastN)
{
    bool removed = false;
	if (first != NULL)
	{
		if ((first -> nCon.get_fn() == firstN) && (first -> nCon.get_ln() == lastN))
		{
			removed = true;
			Node *tempNode = first->next;
			delete first;
			first = tempNode;
			--listSize;
		}

		else
		{
			Node *findNode = first;
			Node *prevNode = first;
			while (findNode != NULL && findNode -> nCon.get_fn() != firstN && findNode -> nCon.get_ln() != lastN)
			{
				prevNode = findNode;
				findNode = findNode->next;
			}
			if (findNode != NULL)
			{
				removed = true;
				prevNode->next = findNode->next;
				delete findNode;
				--listSize;
			}
		}
	} 
    return removed;
}

bool LinkedList::remove(int index)
{
    bool removed = false;
	if (first != NULL && index >= 1 && index <= getSize())
	{
		if (index == 1)
		{
			removed = removeStart();
		}
		else if (index ==getSize())
		{
			removed = removeLast();
		}
		else
		{
			Node *findNode = first;
			Node* prev = NULL;
			int count = 1;
			while (count < index)
			{
				prev = findNode;
				findNode = findNode->next;
				count++;
			}

			Node *delNode = findNode;
			removed = true;
			prev->next = findNode->next;
			delete delNode;
		}

		--listSize;
	}
	return removed;
}


/////////////////////////////////////////////////////////////////////////////////////
//SEARCH FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////////
LinkedList* LinkedList::searchAs(string target, char option)
{
    LinkedList *searchList = new LinkedList();

    //cNode = current node in use
	Node *cNode = first;
	while (cNode)
	{
        //search by first + last
		if (option == 'A' || option == 'a')
		{
			
			if (cNode -> nCon.get_fn() + " " + cNode -> nCon.get_ln() == target)
			{
				searchList -> add2End(cNode -> nCon);
			}
		}
        
        //Search by last name
		else if (option == 'B' || option == 'b')
		{
			if (cNode -> nCon.get_ln() == target)
			{
				searchList -> add2End(cNode -> nCon);
			}
		}

        //Search by ZipCode
		else if (option == 'C' || option == 'c')
		{
			if (cNode -> nCon.get_zip() == target)
			{
				searchList -> add2End(cNode -> nCon);
			}
		}
		
		cNode = cNode -> next;
	}
	return searchList;
}

Contact* LinkedList::modSearch(string first_name, string last_name)
{
	Contact search_for;
	search_for.set_fn(first_name);
	search_for.set_ln(last_name);

	Node* current = first;
	while (current)
	{
		if (current->nCon == search_for) {
			return &current -> nCon;
		}

		current = current -> next;
	}

	return NULL;
}

/////////////////////////////////////////////////////////////////////////////////////
//SORT
/////////////////////////////////////////////////////////////////////////////////////
void LinkedList::sort()
{
	Node *nPtr1 = first;
	Node *nPtr2 = NULL;
	bool swap = false;
	
	if(isEmpty()){
		return;
	}
	
	do{
		swap = false;
		nPtr1 = first;		
    	
		while(nPtr1 -> next != nPtr2){
			
			if( nPtr1 -> next -> nCon < nPtr1 -> nCon){
				
				Contact tempCon;
				tempCon = nPtr1->nCon;
				nPtr1 -> nCon = nPtr1 -> next -> nCon;
				nPtr1 -> next -> nCon = tempCon;
				swap = true;
					
			}
			nPtr1 = nPtr1->next;
		}
		nPtr2 = nPtr1;			
	}
	while(swap);	
}

/////////////////////////////////////////////////////////////////////////////////////
//WRITE TO FILE
/////////////////////////////////////////////////////////////////////////////////////
void LinkedList::write(ofstream &file)
{
	Node *current = first;

	while (current != NULL)
	{
		file << current -> nCon.get_fn() << ',' << current -> nCon.get_ln() << ',' << current -> nCon.get_num() << ',' << current -> nCon.get_addy() << ',' << current -> nCon.get_city() << ',' << current -> nCon.get_zip() << ',' << current -> nCon.get_state();
		current = current -> next;
		if (current != NULL)
		{
			file << '\n';
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////
//OVERLOADED OPERATOR
/////////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os,  LinkedList& c)
{
	LinkedList::Node *last;
	last = c.first;
	int i = 1;
	while(last != NULL){
		os << i << ". ";
		os << last -> nCon << "\n";
		last = last -> next;
		i++;
	}
	cout<<endl;
	return os;
}