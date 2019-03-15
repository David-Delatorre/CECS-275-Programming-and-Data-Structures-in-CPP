#include "player.h"

int main()
{
    Player play;
    srand(time(NULL));
    while (play.takeTurn())
    {
        continue;
    }
    cout << "Game Over!\nFinal score = " << play.getPoints() << " points.";
    cin.get();

    return 0;
}