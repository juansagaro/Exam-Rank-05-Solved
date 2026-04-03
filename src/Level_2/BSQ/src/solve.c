#include "../inc/bsq.h"

void solve_and_print(t_map *map)
{
    int *dp;
    int i, j, temp, prev_diag;
    int max_size = 0, max_i = 0, max_j = 0;

    dp = malloc(sizeof(int) * map->cols);
    if (!dp) return ;
    for (i = 0; i < map->cols; i++) dp[i] = 0;

    for (i = 0; i < map->rows; i++) {
        prev_diag = 0;
        for (j = 0; j < map->cols; j++) {
            temp = dp[j];
            if (map->data[i * (map->cols + 1) + j] == map->obs)
                dp[j] = 0;
            else if (map->data[i * (map->cols + 1) + j] == map->empty) {
                if (i == 0 || j == 0) dp[j] = 1;
                else dp[j] = ft_min(dp[j], dp[j - 1], prev_diag) + 1;
                
                if (dp[j] > max_size) {
                    max_size = dp[j];
                    max_i = i;
                    max_j = j;
                }
            }
            prev_diag = temp;
        }
    }

    for (i = max_i - max_size + 1; i <= max_i; i++)
        for (j = max_j - max_size + 1; j <= max_j; j++)
            map->data[i * (map->cols + 1) + j] = map->full;

    write(1, map->data, map->rows * (map->cols + 1));
    free(dp);
}
