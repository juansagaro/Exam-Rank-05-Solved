#include "../inc/bsq.h"

void solve_map(t_map *map)
{
    int *dp;
    int i, j, temp, prev_diag;

    map->max_size = 0;
    map->max_i = 0;
    map->max_j = 0;

    if (!(dp = calloc(map->cols, sizeof(int)))) return;

    for (i = 0; i < map->rows; i++) {
        prev_diag = 0;
        for (j = 0; j < map->cols; j++) {
            temp = dp[j];
            if (map->grid[i][j] == map->obs)
                dp[j] = 0;
            else if (map->grid[i][j] == map->empty) {
                if (i == 0 || j == 0) 
                    dp[j] = 1;
                else {
                    int m = (dp[j] < dp[j - 1]) ? dp[j] : dp[j - 1];
                    dp[j] = ((m < prev_diag) ? m : prev_diag) + 1;
                }
                if (dp[j] > map->max_size) {
                    map->max_size = dp[j];
                    map->max_i = i;
                    map->max_j = j;
                }
            }
            prev_diag = temp;
        }
    }
    free(dp);
}
