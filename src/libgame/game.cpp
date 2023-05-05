#include "libgame/game.hpp"
#include <iostream>


bool solved;
int field[FIELD_SIZE];
int empty;

void create()
{
    for (int i = 0; i < FIELD_SIZE - 1; i++) {
        field[i] = i + 1;
    }
    int empty = FIELD_SIZE - 1;
    field[empty] = 0;
    solved = true;
}

void Print()
{
    for(int i = 0; i < FIELD_SIZE; i++)
    {
        std::cout << field[i] << " ";
    }
}

bool check()
{
    for (int i = 0; i < FIELD_SIZE - 1; i++) {
        if (field[i] != i + 1) {
            return false;
        }
    }
    return true;
}
