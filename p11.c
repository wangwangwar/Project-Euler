#include<errno.h>
#include<stdio.h>
#include<stdbool.h>

#define LIMIT_ROW 20
#define LIMIT_COL 20

enum direction { DOWN, RIGHT, DOWN_LEFT, DOWN_RIGHT };

bool product(enum direction d, int grid[][LIMIT_COL], int row, int col, int limit_row, int limit_col, int num, unsigned long long *p);

int main(void) {
    int grid[LIMIT_ROW][LIMIT_COL];

    FILE *fgrid = fopen("q11.dat", "r");
    errno = 0;
    if (NULL == fgrid) {
        fprintf(stderr, "open file \"q11.dat\" failed: %s\n", strerror(errno));
        return -1;
    }
    for (int i=0; i<LIMIT_ROW; i++) {
        for (int j=0; j<LIMIT_COL; j++) {
            fscanf(fgrid, "%d", &grid[i][j]);
            printf("%d ", grid[i][j]);
        }
    }

    unsigned long long max = 0;
    for (int i=0; i<LIMIT_ROW; i++) {
        for (int j=0; j<LIMIT_COL; j++) {
            unsigned long long p;
            bool ret;
            ret = product(DOWN, grid, i, j, LIMIT_ROW, LIMIT_COL, 4, &p);
            if (true == ret && max < p) {
                max = p;
            }
            ret = product(RIGHT, grid, i, j, LIMIT_ROW, LIMIT_COL, 4, &p);
            if (true == ret && max < p) {
                max = p;
            }
            ret = product(DOWN_LEFT, grid, i, j, LIMIT_ROW, LIMIT_COL, 4, &p);
            if (true == ret && max < p) {
                max = p;
            }
            ret = product(DOWN_RIGHT, grid, i, j, LIMIT_ROW, LIMIT_COL, 4, &p);
            if (true == ret && max < p) {
                max = p;
            }
            printf("%d %d %ld\n", i, j, max);
        }
    }

    printf("%ld\n", max);

    return 0;
}

/**
 * Get down *num* adjacent number's product.
 * grid: the 2-D array
 * row: the row of start point
 * col: the col of start point
 * limit_row: max row of array
 * limit_col: max col of array
 * num: number of adjacent.
 */
bool product(enum direction d,
        int grid[][LIMIT_COL],
        int row, 
        int col, 
        int limit_row, 
        int limit_col,
        int num,
        unsigned long long *p) {
    switch (d) {
        case DOWN:
            if (row + num - 1 > limit_row) {
                return false;
            } else {
                long long t = 1;
                for (int i = 0; i<num; i++) {
                    t *= grid[row+i][col];
                }
                *p = t;
                return true;
            }
        case RIGHT:
            if (col + num - 1 > limit_col) {
                return false;
            } else {
                long long t = 1;
                for (int i = 0; i<num; i++) {
                    t *= grid[row][col+i];
                }
                *p = t;
                return true;
            }
        case DOWN_LEFT:
            if (row + num - 1 > limit_row || col < num - 1) {
                return false;
            } else {
                long long t = 1;
                for (int i = 0; i<num; i++) {
                    t *= grid[row+i][col-i];
                }
                *p = t;
                return true;
            }
        case DOWN_RIGHT:
            if (row + num - 1 > limit_row || col + num - 1 > limit_col) {
                return false;
            } else {
                long long t = 1;
                for (int i = 0; i<num; i++) {
                    t *= grid[row+i][col+i];
                }
                *p = t;
                return true;
            }
        default:
            return false;
    }
}
