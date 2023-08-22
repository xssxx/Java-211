#include <stdio.h>
#include <stdlib.h>

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int is_valid(int x, int y, int size) {
    return x >= 0 && x < size && y >= 0 && y < size;
}

int find_path(int **grid, int x, int y, int size) {
    if (x == size - 1 && y == size - 1) {
        return 1;
    }

    grid[x][y] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if (is_valid(new_x, new_y, size) && grid[new_x][new_y] == 0 && find_path(grid, new_x, new_y, size)) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int size;
    scanf("%d", &size);

    int **grid = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)calloc(size, sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (find_path(grid, 0, 0, size)) {
        printf("YES");
    } else {
        printf("NO");
    }

    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
