#include <stdio.h>
#include <stdlib.h>

void encryptGrid(int** grid, int r, int c, int key) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) grid[i][j] ^= key;
    }
}

int main() {
    int row[] = {1, 2, 3};
    int* grid[] = {row};
    encryptGrid(grid, 1, 3, 5);
    printf("%d\n", grid[0][0]);
    return 0;
}
