#include "libgame/graphics.hpp"
#include "libgame/game.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    create();
    mix();
    window();
    return 0;
}