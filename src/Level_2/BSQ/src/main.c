#include "../inc/bsq.h"

void process_stream(FILE *stream)
{
    t_map map;

    map.grid = NULL; 
    if (!parse_map(stream, &map))
        fputs("map error\n", stderr);
    else
    {
        solve_map(&map);
        print_map(&map);
    }
    free_map(&map);
}

int main(int argc, char **argv)
{
    int    i = 1;
    FILE   *file;

    if (argc == 1)
        process_stream(stdin);
    else
    {
        while (i < argc)
        {
            file = fopen(argv[i], "r");
            if (!file)
                fputs("map error\n", stderr);
            else
            {
                process_stream(file);
                fclose(file);
            }
            if (i < argc - 1)
                fputs("\n", stdout);
            i++;
        }
    }
    return (0);
}
