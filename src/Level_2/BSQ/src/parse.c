#include "../inc/bsq.h"

char *read_file(int fd)
{
    char    buf[4096];
    char    *res;
    char    *tmp;
    int     ret;
    int     len;
    int     i;
    int     j;

    len = 0;
    res = malloc(1);
    if (!res) return (NULL);
    res[0] = '\0';
    while ((ret = read(fd, buf, 4096)) > 0)
    {
        tmp = malloc(len + ret + 1);
        if (!tmp) { free(res); return (NULL); }
        for (i = 0; i < len; i++) tmp[i] = res[i];
        for (j = 0; j < ret; j++) tmp[i++] = buf[j];
        tmp[i] = '\0';
        free(res);
        res = tmp;
        len += ret;
    }
    if (ret < 0 || len == 0) { free(res); return (NULL); }
    return (res);
}

int parse_map(char *raw, t_map *map)
{
    int i = 0, j = 0, first_len = 0, current_rows = 0;

    while (raw[first_len] && raw[first_len] != '\n') first_len++;
    if (first_len < 4) return (0);

    map->full = raw[first_len - 1];
    map->obs = raw[first_len - 2];
    map->empty = raw[first_len - 3];
    if (map->full == map->obs || map->full == map->empty || map->obs == map->empty)
        return (0);

    map->rows = 0;
    while (i < first_len - 3) {
        if (raw[i] < '0' || raw[i] > '9') return (0);
        map->rows = map->rows * 10 + (raw[i] - '0');
        i++;
    }

    map->data = raw + first_len + 1;
    if (!*(map->data)) return (0);

    map->cols = 0;
    while (map->data[map->cols] && map->data[map->cols] != '\n') map->cols++;
    if (map->cols == 0) return (0);

    i = 0;
    while (map->data[i]) {
        if (map->data[i] == '\n') {
            if (j != map->cols) return (0);
            current_rows++;
            j = 0;
        } else {
            if (map->data[i] != map->empty && map->data[i] != map->obs) return (0);
            j++;
        }
        i++;
    }
    return (current_rows == map->rows && j == 0);
}
