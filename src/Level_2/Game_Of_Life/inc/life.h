#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int get_cell(int *board, int w, int h, int x, int y);
int count_neighbors(int *board, int w, int h, int x, int y);

#endif
