#include "libgame/game.hpp"
#include <iostream>
#include <iomanip>


int field[FIELD_SIZE];
int empty;

void create()
{
    for (int i = 0; i < FIELD_SIZE - 1; i++) {
        field[i] = i + 1;
    }
    empty = FIELD_SIZE - 1;
    field[empty] = 0;
}

void Print()
{
    int k = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << std::setw(4) << field[k] << " ";
            k++;
        }
        std::cout << std::endl;
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
        case 71:
        if(column < 3)
        {
            flag = empty + 1;
        }
        break;

        case 72:
        if(column > 0)
        {
            flag = empty - 1;
        }
        break;

        case 73:
        if(row < 3)
        {
            flag = empty + 4;
        }
        break;

        case 74:
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
}

void mix()
{
    int random_moves = 1000;
    while(random_moves > 0)
    {
        move(71 + rand() % 4);
        random_moves--;
    }
}