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

void move(char direction)
{
    int column = empty % 4;
    int row = empty / 4;
    int flag = -1;
    switch(direction)
    {
        case 75:
        if(column < 5)
        {
            flag = empty + 1;
        }
        break;

        case 77:
        if(column > 0)
        {
            flag = empty - 1;
        }
        break;

        case 72:
        if(row < 3)
        {
            flag = empty + 4;
        }
        break;

        case 80:
        if(row > 0)
        {
            flag = empty - 4;
        }
        break;
    }
    if(empty >= 0 && flag >= 0)
    {
        int c = field[empty];
        field[empty] = field[flag];
        field[flag] = c;
        empty = flag;
    }
    solved = check();
}