#include "libgame/graphics.hpp"
#include "libgame/game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
    srand(time(NULL));
    create();
    int random_moves = 1000;
    while(random_moves > 0)
    {
        move(71 + rand() % 4);
        random_moves--;
    }
    window();
    return 0;
}