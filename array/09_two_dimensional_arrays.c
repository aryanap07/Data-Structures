/*
 * 09_two_dimensional_arrays.c
 * Topics: 3.9, 3.9.1, 3.9.2, 3.9.3
 * Declaration, initialization, and access of 2D arrays.
 */

#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    size_t rows = sizeof(matrix) / sizeof(matrix[0]);
    size_t columns = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            printf("matrix[%zu][%zu] = %d\n",
                   row, column, matrix[row][column]);
        }
    }

    printf("\nMatrix:\n");
    for (size_t row = 0; row < rows; ++row) {
        for (size_t column = 0; column < columns; ++column) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }

    return 0;
}
