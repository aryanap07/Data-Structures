/*
 * 12_pointers_and_2d_arrays.c
 * Topic: 3.12 - Pointers and Two-Dimensional Arrays
 */

#include <stdio.h>

#define ROWS 2
#define COLUMNS 3

int main(void)
{
    int matrix[ROWS][COLUMNS] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int (*pointer)[COLUMNS] = matrix;

    printf("Using pointer to an array:\n");
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            printf("%d ", pointer[row][column]);
        }
        printf("\n");
    }

    printf("\nElement [1][2] using pointer arithmetic: %d\n",
           *(*(pointer + 1) + 2));

    return 0;
}
