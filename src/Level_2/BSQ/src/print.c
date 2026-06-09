#include "../inc/bsq.h"

void print_map(t_map *map)
{
    int i, j;

    for (i = 0; i < map->max_size; i++)
        for (j = 0; j < map->max_size; j++)
            map->grid[map->max_i - i][map->max_j - j] = map->full;

    for (i = 0; i < map->rows; i++)
    {
        fputs(map->grid[i], stdout);
        fputs("\n", stdout);
    }
}
