#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <fstream>

using namespace std;

class Contact
{
    private:
    //first name of contact
        string firstName;
    //last name of contact
        string lastName;
    //phone number of contact
        string phoneNumber;
    //address of contact
        string address;
    //city of contact
        string city;
    //zipcode of contact
        string zipCode;
    //state of contact
        string state;

    public:
        //default constructor
        Contact();

        //Overloaded constructor
        //@param = fn = first name
        //@param = ln = last name
        Contact(string fn, string ln);

        //Overloaded constructor 
        //@param = fn = first name
        //@param = ln = last name
        //@param = pn = phone number
        //@param = addy = address
        //@param = nCity = city
        //@param = zc = zipcode
        //@param = nState = state
        Contact(string fn, string ln, string pn, string addy, string nCity, string zc, string nState);
        
        //Setters
        string get_fn();
        string get_ln();
        string get_num();
        string get_addy();
        string get_city();
        string get_zip();
        string get_state();

        //Getters
        void set_fn(string fn);
        void set_ln(string ln);
        void set_num(string pn);
        void set_addy(string addy);
        void set_city(string nCity);
        void set_zip(string zc);
        void set_state(string nState);


        bool operator<(Contact con);
        bool operator==(Contact con);
        friend ostream &operator<< (ostream &out, Contact con);
        friend istream &operator>> (istream &in, Contact &con);
};

#endif 