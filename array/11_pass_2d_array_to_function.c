/*
 * 11_pass_2d_array_to_function.c
 * Topic: 3.11 - Passing Two-Dimensional Arrays to Functions
 */

#include <stdio.h>

#define ROWS 2
#define COLUMNS 3

static void print_matrix(const int matrix[ROWS][COLUMNS])
{
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}

static int sum_matrix(const int matrix[ROWS][COLUMNS])
{
    int sum = 0;

    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            sum += matrix[row][column];
        }
    }

    return sum;
}

int main(void)
{
    const int matrix[ROWS][COLUMNS] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    print_matrix(matrix);
    printf("Sum = %d\n", sum_matrix(matrix));

    return 0;
}
