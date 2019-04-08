#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

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
        Contact(string fiN, string lN, string pN, string addr, string cT, string zC, string st);
        string get_fn();
        string get_ln();
        string get_num();
        string get_addy();
        string get_city();
        string get_zip();

        void set_fn(string fn);
        void set_ln(string ln);
        void set_num(string pn);
        void set_city(string town);
        void set_zip(string zc);
        void set_state(string st);

        int operator<(Contact con1, Contact con2);
        Contact operator==(Contact con);
        friend ostream &operator<< (ostream &out, Contact con);
        friend istream &operator >> (istream &in, Contact &con);
};

#endif 