#include "die.h"

Die::Die()
{
    sides = 6;
    value = 1;
}
Die::Die(int s) 
{
    sides = s;
    value = 1;
}

int Die::roll()
{
    //srand(time(NULL));
    value = rand() % sides + 1;
    return value;
}

int Die::getValue()
{
    return value;
}

bool Die::setValue (int val)
{
    if (val > 0 && val <= sides)
    {
        value = val;
        return true;
    }
    return false;
}