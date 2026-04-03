#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map {
    int     rows;
    int     cols;
    char    empty;
    char    obs;
    char    full;
    char    *data;
} t_map;

/* utils.c */
void    ft_putstr_fd(char *s, int fd);
int     ft_min(int a, int b, int c);

/* parse.c */
char    *read_file(int fd);
int     parse_map(char *raw, t_map *map);

/* solve.c */
void    solve_and_print(t_map *map);

#endif
