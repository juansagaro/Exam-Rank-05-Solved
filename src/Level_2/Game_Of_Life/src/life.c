#include "../inc/life.h"

// Return a cell state, treating out-of-bounds positions as dead.
int get_cell(int *board, int w, int h, int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h)
        return 0;
    return board[y * w + x];
}

// Count live neighbors around (x, y).
int count_neighbors(int *board, int w, int h, int x, int y) {
    int count = 0;
    // Explore the 3x3 area centered on the current cell.
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            // Skip the center cell itself.
            if (dx == 0 && dy == 0)
                continue;
            count += get_cell(board, w, h, x + dx, y + dy);
        }
    }
    return count;
}

int main(int argc, char **argv) {
    if (argc != 4)
        return 0;

    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    int iters = atoi(argv[3]);

    if (w <= 0 || h <= 0 || iters < 0)
        return 0;

    // calloc starts the whole board as dead cells.
    int *board = calloc(w * h, sizeof(int));
    if (!board)
        return 1;

    char c;
    int px = 0, py = 0;
    int drawing = 0; // 0: pen up, 1: pen down.

    // Phase 1: read drawing commands from stdin.
    while (read(0, &c, 1) > 0) {
        if (c == 'w') py--;
        else if (c == 's') py++;
        else if (c == 'a') px--;
        else if (c == 'd') px++;
        else if (c == 'x') {
            drawing = !drawing;
            // Draw immediately when the pen is lowered.
            if (drawing) {
                if (px >= 0 && px < w && py >= 0 && py < h)
                    board[py * w + px] = 1;
            }
        }

        // Any movement draws on the new position while pen is down.
        if ((c == 'w' || c == 's' || c == 'a' || c == 'd') && drawing) {
            if (px >= 0 && px < w && py >= 0 && py < h)
                board[py * w + px] = 1;
        }
    }

    // Phase 2: run Conway's Game of Life.
    for (int i = 0; i < iters; i++) {
        // Next generation buffer.
        int *next = calloc(w * h, sizeof(int));
        if (!next) {
            free(board);
            return 1;
        }

        // Compute each cell transition from its neighborhood.
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int n = count_neighbors(board, w, h, x, y);
                int idx = y * w + x;
                
                if (board[idx] == 1) {
                    if (n == 2 || n == 3)
                        next[idx] = 1;
                } else {
                    if (n == 3)
                        next[idx] = 1;
                }
            }
        }
        // Move to the next generation.
        free(board);
        board = next;
    }

    // Phase 3: print final board.
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            putchar(board[y * w + x] ? 'O' : ' ');
        }
        putchar('\n');
    }

    free(board);
    return 0;
}
