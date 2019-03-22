#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class contact
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
        contact();
        contact(string fiN, string lN, string pN, string addr, string cT, string zC, string st);
        void display();
        void readFile(vector<string> test);
};

#endif 