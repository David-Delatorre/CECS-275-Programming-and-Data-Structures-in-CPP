#include "LinkedList.h"
#include <fstream>
#include <iostream>
using namespace std;

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
int getCharRange(char first_alpha, char last_alpha) { /* gets a valid integer between the two parameters (inclusive) */
	char search_by;
	string user_input;
	bool valid = false;
	while (!valid) {
		if (cin >> user_input) {
			if (user_input.size() > 1)
			{
				cout << "Invalid Input. Please choose a letter between (A-C): " << endl;
			}
			else
			{
				search_by = toupper(user_input[0]);

				if (search_by >= first_alpha && search_by <= last_alpha)
				{
					valid = true;
				}
				else
				{
					cout << "Invalid Input. Please choose a letter between (A-C): " << endl;
				}
			}
		}
		else {
			cin.clear();
			string invalid;
			cin >> invalid;
			cout << "Invalid Input. " << endl;
		}
		while (cin.get() != '\n') continue;
	}
	return search_by;
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

void menu()
{
    cout << "Rolodex Menu:"<<endl;
    cout << "1. Add Contact"<<endl;
    cout << "2. Remove Contact"<<endl;
    cout << "3. Search for Contact"<<endl;
    cout << "4. Modify Contact"<<endl;
    cout << "5. Display Contacts"<<endl;
    cout << "6. Quit"<<endl;
}

void search_menu()
{
    cout << "Search Menu:"<<endl;
    cout << "A. Search By Full Name"<<endl;
    cout << "B. Search By Last Name"<<endl;
    cout << "C. Search By Zip-code"<<endl;
}

int main() 
{
    LinkedList contacts;
	string rolodex = "addresses.txt";
    loadFile(contacts, rolodex);

    int menu_number = 0;
    while (menu_number != 6)
    {
        menu();
        menu_number = getIntRange(1, 6);

        switch (menu_number)
        {
            case 1: 
            {
                cout << "Add Menu:\n";

                Contact new_contact;
                cin >> new_contact;

                contacts.add2End(new_contact);
                break;
            }

            case 3:
            {
                search_menu();

                char search_by = getCharRange('A', 'C');
                string temp;

                if (search_by == 'A')
                {
                    string first, last;

                    cout << "Enter First Name: ";
                    cin >> first;

                    cout << "Enter Last Name: ";
                    cin >> last;

                    Contact* contact = contacts.searchAs(first, last);
                    if (contact)
                        cout << contact;
                }
                else if (search_by == 'B')
                {
                    cout << "Enter Last Name: ";
                    cin >> temp;

                    LinkedList* list = contacts.searchAs(temp,search_by);
                    
                    if (list)
                        cout << *list;
                } 
                else if (search_by == 'C')
				{
                    cout << "Enter Zip-Code: ";
                    cin >> temp;

                   LinkedList* list = contacts.searchAs(temp,search_by);
                    
                    if (list)
                        cout << *list;
                }
				else
                {  
                    cout << "Invalid input"<<endl;
                }
                
                break;
            }
            case 5:
            {
                cout << contacts;
                break;
            }
        }
    }
    cout << "Quiting...\n";
    cin.get();  
}
