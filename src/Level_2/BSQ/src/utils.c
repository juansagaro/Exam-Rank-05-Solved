#include "../inc/bsq.h"

void ft_putstr_fd(char *s, int fd)
{
    int len;

    len = 0;
    if (!s)
        return ;
    while (s[len])
        len++;
    write(fd, s, len);
}

int ft_min(int a, int b, int c)
{
    int min;

    min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return (min);
}
