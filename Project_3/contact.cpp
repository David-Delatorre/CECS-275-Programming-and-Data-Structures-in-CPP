#include "contact.h"

/////////////////////////////////////////////////////////////////////////////////////
//CONSTRUCTORS
/////////////////////////////////////////////////////////////////////////////////////

//Default constructor
Contact::Contact()
{
    //initializing all to empty strings
    firstName = " ";
    lastName = " ";
    phoneNumber = " ";
    address = " ";
    city = " ";
    zipCode = " ";
    state = " ";
}

//Overloaded constructor
//@param fn = first name
//@param ln = last name
//Allows user input for first + last name
Contact::Contact(string fn, string ln)
{
    firstName = fn;
    lastName = ln;
    phoneNumber = " ";
    address = " ";
    city = " ";
    zipCode = " ";
    state = " ";
}

Contact::Contact(string fn, string ln, string pn, string addy, string nCity, string zc, string nState)
{
    firstName = fn;
    lastName = ln;
    phoneNumber = pn;
    address = addy;
    city = nCity;
    zipCode = zc;
    state = nState;
}

/////////////////////////////////////////////////////////////////////////////////////
//GETTERS
/////////////////////////////////////////////////////////////////////////////////////
string Contact::get_fn()
{
    return firstName;
}

string Contact::get_ln()
{
    return lastName;
}

string Contact::get_num()
{
    return phoneNumber;
}

string Contact::get_addy()
{
    return address;
}

string Contact::get_city()
{
    return city;
}

string Contact::get_zip()
{
    return zipCode;
}

string Contact::get_state()
{
    return state;
}

/////////////////////////////////////////////////////////////////////////////////////
//SETTERS
/////////////////////////////////////////////////////////////////////////////////////
void Contact::set_fn(string fn)
{
    firstName = fn;
}

void Contact::set_ln(string ln)
{
    lastName = ln;
}

void Contact::set_num(string pn)
{
    phoneNumber = pn;
}

void Contact::set_addy(string addy)
{
    address = addy;
}

void Contact::set_city(string nCity)
{
    city = nCity;
}

void Contact::set_zip(string zc)
{
    zipCode = zc;
}

void Contact::set_state(string nState)
{
    state = nState;
}

/////////////////////////////////////////////////////////////////////////////////////
//OVERLOADED OPERATORS
/////////////////////////////////////////////////////////////////////////////////////

bool Contact::operator<(Contact con)
{
    //using .compare function
    //if 0, then strings are equal
    //if <0, then compared string is shorter
    //if >0, then compared string is longer
    int compare;
    compare = this -> lastName.compare(con.lastName);

    if (compare < 0)   return true;
    
    //For people with the same last name, compare first names instead
    else if (compare == 0)
    {
        compare = this -> firstName.compare(con.lastName);

        if (compare < 0)    return true;
    }
    return false;
}

bool Contact::operator==(Contact con)
{
    if ((this -> lastName == con.get_ln()) && (this -> firstName == con.get_fn()))
    { 
        return true;
    }
    return false;
}

istream &operator >> (istream &in, Contact &con)
{ 
    string input;

    cin.ignore();//Prevent the previous input to be input into the first name
    cout << "Enter First Name: ";
    getline(in, input);
    con.set_fn(input);

    cout << "Enter Last Name: ";
    getline(in, input);
    con.set_ln(input);

    cout << "Enter Phone #: ";
    getline(in, input);
    con.set_num(input);

    cout << "Enter Address: \n";
    getline(in, input);
    con.set_addy(input);

    cout << "Enter City: ";
    getline(in, input);
    con.set_city(input);

    cout << "Enter Zip-Code: ";
    getline(in, input);
    con.set_zip(input);

    cout << "Enter State: ";
    getline(in, input);
    con.set_state(input);

    return in;
}

ostream &operator<< (ostream &out, Contact con)
{
    out << con.firstName + " " + con.lastName + "\n";
    out << con.phoneNumber + "\n";
    out << con.address + "\n";
    out << con.city + " " + con.zipCode + " " + con.state + "\n";
    return out;
}