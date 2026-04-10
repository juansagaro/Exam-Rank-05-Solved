#include "../inc/life.h"

// Obtiene el estado de una celda. Si nos salimos de los límites, se considera muerta (0).
int get_cell(int *board, int w, int h, int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h)
        return 0;
    return board[y * w + x];
}

// Cuenta los vecinos vivos alrededor de una coordenada exacta (x, y)
int count_neighbors(int *board, int w, int h, int x, int y) {
    int count = 0;
    // Comprobamos la cuadrícula de 3x3 centrada en nuestra celda
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            // Saltamos la propia celda central (nuestra celda no es su propia vecina)
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

    // Utilizamos calloc para asegurar que todo el tablero empiece relleno con ceros
    int *board = calloc(w * h, sizeof(int));
    if (!board)
        return 1;

    char c;
    int px = 0, py = 0;
    int drawing = 0; // 0 = Lápiz levantado (no pinta), 1 = Lápiz bajado (pinta)

    // Fase 1: Leer los comandos de dibujo desde la entrada estándar
    while (read(0, &c, 1) > 0) {
        if (c == 'w') py--;
        else if (c == 's') py++;
        else if (c == 'a') px--;
        else if (c == 'd') px++;
        else if (c == 'x') {
            drawing = !drawing; // Cambiamos el estado del lápiz
            // Si acabamos de bajar el lápiz, dibujamos inmediatamente en la casilla actual
            if (drawing) {
                if (px >= 0 && px < w && py >= 0 && py < h)
                    board[py * w + px] = 1;
            }
        }

        // Si nos hemos movido (w,a,s,d) y el lápiz está bajado, pintamos la nueva casilla
        if ((c == 'w' || c == 's' || c == 'a' || c == 'd') && drawing) {
            if (px >= 0 && px < w && py >= 0 && py < h)
                board[py * w + px] = 1;
        }
    }

    // Fase 2: Simulación del Juego de la Vida
    for (int i = 0; i < iters; i++) {
        // Tablero para el siguiente "turno" (buffer)
        int *next = calloc(w * h, sizeof(int));
        if (!next) {
            free(board);
            return 1;
        }

        // Iterar y calcular el destino de cada celda basándose en los vecinos
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int n = count_neighbors(board, w, h, x, y);
                int idx = y * w + x;
                
                if (board[idx] == 1) { // Celda viva
                    if (n == 2 || n == 3)
                        next[idx] = 1; // Sobrevive
                } else { // Celda muerta
                    if (n == 3)
                        next[idx] = 1; // Nace (Reproducción)
                }
            }
        }
        // Sobrescribimos el tablero y avanzamos turno
        free(board);
        board = next;
    }

    // Fase 3: Imprimir el tablero final
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            putchar(board[y * w + x] ? 'O' : ' ');
        }
        putchar('\n');
    }

    free(board);
    return 0;
}
