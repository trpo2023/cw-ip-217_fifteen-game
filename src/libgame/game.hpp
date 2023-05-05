#pragma once
const int FIELD_SIZE = 16;
const int WINDOW_SIZE = 500;
const int CELL_SIZE = 120;

extern int field[FIELD_SIZE];
extern int empty;


void create();

bool check();

void Print();
