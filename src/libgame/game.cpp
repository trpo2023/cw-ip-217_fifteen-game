#include <iostream>
#include "libgame/game.hpp"

bool solved;

void create()
{
    int field[FIELD_SIZE];
    for(int i = 0; i < FIELD_SIZE-1; i++)
    {
        field[i] = i + 1;
    }
    field[FIELD_SIZE-1] = 0;
    solved = true;
    for(int i = 0; i < FIELD_SIZE-1; i++)
    {
        std::cout << field[i] << " ";
    }
}