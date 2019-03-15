#ifndef DIE_H
#define DIE_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

class Die   
{
    private:
        int sides;//Num of sides of die
        int value;//value shown by die
    
    public:
        Die();
        Die(int s); 
        int roll();
        int getValue();
        bool setValue (int val);
};

#endif