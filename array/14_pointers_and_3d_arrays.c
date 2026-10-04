/*
 * 14_pointers_and_3d_arrays.c
 * Topic: 3.14 - Pointers and Three-dimensional Arrays
 */

#include <stdio.h>

#define ROWS 2
#define COLUMNS 2
#define DEPTH 3

int main(void)
{
    int cube[ROWS][COLUMNS][DEPTH] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}
    };

    int (*pointer)[COLUMNS][DEPTH] = cube;

    printf("cube[1][0][2] = %d\n", pointer[1][0][2]);
    printf("Same element using pointer arithmetic = %d\n",
           *(*(*(pointer + 1) + 0) + 2));

    return 0;
}
