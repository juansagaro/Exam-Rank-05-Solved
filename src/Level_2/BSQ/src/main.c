#include "../inc/bsq.h"

void process_fd(int fd)
{
    char    *raw;
    t_map   map;

    raw = read_file(fd);
    if (!raw || !parse_map(raw, &map))
        ft_putstr_fd("map error\n", 2);
    else
        solve_and_print(&map);
    if (raw)
        free(raw);
}

int main(int argc, char **argv)
{
    int i;
    int fd;

    i = 1;
    if (argc == 1)
        process_fd(0);
    else
    {
        while (i < argc)
        {
            fd = open(argv[i], O_RDONLY);
            if (fd < 0)
                ft_putstr_fd("map error\n", 2);
            else
            {
                process_fd(fd);
                close(fd);
            }
            if (i < argc - 1)
                write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}
