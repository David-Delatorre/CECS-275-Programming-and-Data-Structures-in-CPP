#include "contact.h"

#include <iostream>
using namespace std;

Contact::Contact()
{
    //DEFAULT CONSTRUCTOR w/ no body
    // firstName = "Louis";
    // lastName = "Monfiero";
    // phoneNumber = "220-8888";
    // address = "99 Santa Monica St.";
    // city = "Cypress";
    // zipCode = "90630";
    // state = "California";
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

void Contact::set_city(string town)
{
    city = town;
}

void Contact::set_zip(string zc)
{
    zipCode = zc;
}

void Contact::set_state(string st)
{
    state = st;
}

/////////////////////////////////////////////////////////////////////////////////////
//OVERLOADED OPERATORS
/////////////////////////////////////////////////////////////////////////////////////

bool Contact::operator<(Contact con)
{
    if (lastName < con.get_ln())
    {
        if (firstName < con.get_fn())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool Contact::operator==(Contact con)
{
    if (lastName == con.get_ln() && firstName == con.get_fn())
    { 
        return true;
    }
    return false;
}

istream &operator >> (istream &in, Contact &con)
{ 
    string input;

    cout << "Enter First Name: ";
    in >> input;
    con.set_fn(input);

    cout << "Enter Last Name: ";
    in >> input;
    con.set_ln(input);

    cout << "Enter Phone #: ";
    in >> input;
    con.set_num(input);

    cout << "Enter Address: \n";
    in >> input;
    con.set_addy(input);

    cout << "Enter City: ";
    in >> input;
    con.set_city(input);

    cout << "Enter Zip-Code: ";
    in >> input;
    con.set_zip(input);

    cout << "Enter State: ";
    in >> input;
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