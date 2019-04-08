#include "contact.h"

Contact::Contact()
{
    firstName = "Louis";
    lastName = "Monfiero";
    phoneNumber = "220-8888";
    address = "99 Santa Monica St.";
    city = "Cypress";
    zipCode = "90630";
    state = "California";
}

Contact::Contact(string fiN, string lN, string pN, string addr, string cT, string zC, string s)
{
    firstName = fiN;
    lastName = lN;
    phoneNumber = pN;
    address = addr;
    city = cT;
    zipCode = zC;
    state = s;
}

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

void Contact::set_city(string town)
{
    city = town;
}

void Contact::set_zip(string zc)
{
    zc = zipCode;
}

void Contact::set_state(string st)
{
    state = st;
}



int Contact::operator<(Contact con1, Contact con2)
{
    if (con1.get_ln.compare(con2.get_ln) == 0)
    {
        return (con1.get_fn.compare(con2.get_fn));
    }
    return con1.get_ln.compare(con2.get_ln);
    
}

istream &operator >> (istream &in, Contact &con)
{ 
    cout << "Enter First Name: ";
    cin >> con.firstName;
    cout << "Enter Last Name: ";
    cin >> con.lastName;
    cout << "Enter Phone #: ";
    cin >> con.phoneNumber;
    cout << "Enter Address: \n";
    cin >> con.address;
    cout << "Enter City: ";
    cin >> con.city;
    cout << "Enter Zip-Code: ";
    cin >> con.zipCode;
    cout << "Enter State: ";
    cin >> con.state;
    return in;
}

ostream &operator<< (ostream &out, Contact con)
{
    out << con.firstName << " " << con.lastName << ": " << con.phoneNumber << endl << con.address + " " + con.city + ", " + con.state + " " + con.zipCode;
    return out;
}


