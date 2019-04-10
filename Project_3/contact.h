#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using namespace std;

class Contact
{
    private:
        string firstName;
        string lastName;
        string phoneNumber;
        string address;
        string city;
        string zipCode;
        string state;

    public:
        Contact();
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
        void set_city(string town);
        void set_zip(string zc);
        void set_state(string st);


        bool operator<(Contact con);
        bool operator==(Contact con);
        friend ostream &operator<< (ostream &out, Contact con);
        friend istream &operator>> (istream &in, Contact &con);
};

#endif 