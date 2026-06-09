# pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct s_map {
    int     rows;
    int     cols;
    char    empty;
    char    obs;
    char    full;
    char    **grid;
    int     max_size;
    int     max_i;
    int     max_j;
} t_map;

int     parse_map(FILE *stream, t_map *map);
void    solve_map(t_map *map);
void    print_map(t_map *map);
void    free_map(t_map *map);
