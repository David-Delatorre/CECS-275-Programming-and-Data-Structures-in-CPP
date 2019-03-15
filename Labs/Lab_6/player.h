#ifndef PLAYER_H
#define PLAYER_H

#include "die.h"

class Player
{
    private: 
        int dice[3];
        int points;
        int size;
    
    public:
        Player();//default constructor
        int getPoints();
        void sortDie();
        void displayVal();
        bool winCond1();//series
        bool winCond2();//pair
        bool winCond3();//three of a kind
        bool takeTurn();
        bool getYesNo();
};

#endif