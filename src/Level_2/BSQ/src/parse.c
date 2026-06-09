#include "../inc/bsq.h"

void free_map(t_map *map)
{
    // Rows are allocated independently, then the row pointer array.
    if (!map->grid) return;
    for (int i = 0; i < map->rows; i++)
        free(map->grid[i]);
    free(map->grid);
    map->grid = NULL;
}

int parse_map(FILE *stream, t_map *map)
{
    char    *line = NULL;
    size_t  len = 0;
    ssize_t r_len;
    int     i = 0;

    if (fscanf(stream, "%d %c %c %c\n", &map->rows, &map->empty, &map->obs, &map->full) != 4)
        return (0);
    if (map->rows <= 0 || map->empty == map->obs || map->empty == map->full || map->obs == map->full)
        return (0);

    // One pointer per row, each row filled by getline.
    if (!(map->grid = calloc(map->rows, sizeof(char *)))) return (0);

    while (i < map->rows)
    {
        if ((r_len = getline(&line, &len, stream)) <= 0) return (0);
        if (line[r_len - 1] == '\n') line[--r_len] = '\0';

        if (i == 0) map->cols = r_len;
        if (r_len != map->cols || map->cols == 0) { free(line); return (0); }

        for (int j = 0; j < map->cols; j++)
            if (line[j] != map->empty && line[j] != map->obs) return (0);

        map->grid[i++] = line;
        line = NULL;
        len = 0;
    }

    if (getline(&line, &len, stream) > 0) { free(line); return (0); }
    free(line);
    return (1);
}
