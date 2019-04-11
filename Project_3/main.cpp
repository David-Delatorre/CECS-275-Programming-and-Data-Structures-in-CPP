#include "LinkedList.h"

/* gets a valid integer between the two parameters (inclusive) */
int getIntRange(int low, int high) {
	int input = 0;
	bool valid = false;
	while(!valid) {
		if(cin >> input) {
			if(input >= low && input <= high) {
				valid = true;
			} else {
				cout<< "Invalid Input" << endl;
			}
		} else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout<< "Invalid Input" << endl;
		}
	}
	return input;
}

int getChar()
{
    string input;
    int len = 0;
    int ascii;
    bool valid = false;
    cout << "\nEnter Letter: ";
    
    while (!valid)
    {
        cin >> input;
        cout << endl;
        ascii = (int) input[0];
        len = input.length();
        
        if (len > 1)
        {
            cout << "Multiple Characters entered.\nTry again: ";
        }
        
        else if ((ascii >= 97 && ascii <= 103) || (ascii >= 65 && ascii <= 71) || (ascii == 81) || (ascii == 113))
        {
            if (ascii >= 97) return ascii;//97a, 98b, 99c, 100d, 101e, 102f, 103g, 113q lowercase
            return ascii;//65A, 66B, 67C, 68D, 69E, 70F, 71G, 81Q uppercase
        }
        
        else
        {
            cout << "Enter Valid Character: ";
        }
    }
    return 0;
}

bool modContact(char choice, Contact *con)
{
	string input;
	if ((choice == 'A') || (choice == 'a'))
	{
		cout << "Change First Name: ";
		cin >> input;
		con -> set_fn(input);
	}
	else if ((choice == 'B') || (choice == 'b'))
	{
		cout << "Change Last Name: ";
		cin >> input;
		con -> set_ln(input);
	}

	else if ((choice == 'C') || (choice == 'c'))
	{
		cout << "Change Phone Number: ";
		cin >> input;
		con -> set_num(input);
	}

	else if ((choice == 'D') || (choice == 'd'))
	{
		cout << "Change Address: \n";
		cin >> input;
		con -> set_addy(input);
	}

	else if ((choice == 'E') || (choice == 'e'))
	{
		cout << "Change City: \n";
		cin >> input;
		con -> set_city(input);
	}

	else if ((choice == 'F') || (choice == 'f'))
	{
		cout << "Change Zip-Code:\n";
		cin >> input;
		con -> set_zip(input);
	}

	else if ((choice == 'G') || (choice == 'g'))
	{
		cout << "Change State:\n";
		cin >> input;
		con -> set_state(input);
	}

	else if ((choice == 'Q' || choice == 'q'))
	{
		return true;
	}

	return false;
}

void loadFile(LinkedList &contact, string rolodex)
{
    Contact con;
    string line;
    fstream file;
    file.open(rolodex, ios::in);

    if (!file)
    {
        cout << "If an item does not appear in our records, then it does not exist!\n";
    }
    
    while (!file.eof())
    {
        getline(file, line, ',');
        con.set_fn(line);

        getline(file, line, ',');
        con.set_ln(line);

        getline(file, line, ',');
        con.set_num(line);

        getline(file, line, ',');
        con.set_addy(line);

        getline(file, line, ',');
        con.set_city(line);

        getline(file, line, ',');
        con.set_zip(line);

        getline(file, line);
        con.set_state(line);

        contact.add2End(con);
    }
}

void mainMenu()
{
    cout << "Rolodex Menu:\n1. Add Contact\n2. Remove Contact\n3. Search for Contact\n4. Modify Contact\n5. Display Contacts\n6. Quit\n";
}

void searchMenu()
{
    cout << "Search Menu:\nA. Search By Full Name\nB. Search By Last Name\nC. Search By Zip-Code\n";
}

void remMenu() 
{ 
	cout << "Remove Menu:\nA. Remove by First + Last Name\nB. Remove by Index in List\n"; 
}

void modMenu()
{
	cout << "A. Enter First Name\nB. Enter Last Name\nC. Enter Phone Number\nD. Enter Address\nE. Enter City\nF. Enter Zip-Code\nG. Enter State\nQ. Save and Quit\n";
}

int main() 
{
    LinkedList contacts;
	string rolodex = "addresses.txt";
    loadFile(contacts, rolodex);
    contacts.sort();
    int menuChoice = 0;
    while (menuChoice != 6)
    {
        mainMenu();
        menuChoice = getIntRange(1, 6);

        switch (menuChoice)
        {
            case 1: 
            {
                cout << "Add Menu:\n";

                Contact nCon;
                cin >> nCon;

                contacts.add2End(nCon);
                break;
            }

            case 2:
            {
                remMenu();
                char choice = getChar();
                string first, last;
                int index;

                if ((choice == 'A') || (choice == 'a'))
                {
                    cout << "Enter First Name: ";
                    cin >> first;

                    cout << "Enter Last Name: ";
                    cin >> last;

                    contacts.remove(first, last);
                }

                else if ((choice == 'B') || (choice == 'b'))
                {
                    cout << "Enter index: ";
                    cin >> index;

                    contacts.remove(index);
                }
                break;
            }

            case 3:
            {
                searchMenu();

                char target = getChar();
                string f, l, in;

                if (target == 'A' || target == 'a')
                {

                    cout << "Enter First Name: ";
                    cin >> f;

                    cout << "Enter Last Name: ";
                    cin >> l;

                    LinkedList* list = contacts.searchAs(f + " " + l, target);
                    if (list)
                        cout << *list;
                }

                else if (target == 'B' || target == 'b')
                {
                    cout << "Enter Last Name: ";
                    cin >> in; 

                    LinkedList* list = contacts.searchAs(in, target);
                    
                    if (list)
                        cout << *list;
                } 

                else if (target == 'C' || target == 'c')
				{
                    cout << "Enter Zip-Code: ";
                    cin >> in; 

                   LinkedList* list = contacts.searchAs(in, target);
                    
                    if (list)
                        cout << *list;
                }
				
                else
                {  
                    cout << "Invalid input!"<<endl;
                }
                
                break;
            }

            case 4:
            {
                string first, last;

                cout << "Enter First Name: ";
                cin >> first;

                cout << "Enter Last Name: ";
                cin >> last;

                Contact *contact = contacts.modSearch(first, last);
                string input;
                if (contact != NULL)
                {
                    bool test = false;
                    while (!test)
                    {
                        modMenu();

                        char choice = getChar();

                        test = modContact(choice, contact);

                    }
                }
                break;
            }

            case 5:
            {
                cout << contacts;
                break;
            }

            case 6:
            {
                ofstream file("addresses.txt");
                contacts.write(file);
                break;
            }
        }
    }
    cout << "Exiting Program..\n"; 
}
