/*
 * 10_two_dimensional_operations.c
 * Topic: 3.10 - Operations on Two-Dimensional Arrays
 * Example operations: matrix addition and transpose.
 */

#include <stdio.h>

#define ROWS 2
#define COLUMNS 3

static void print_matrix(int matrix[][COLUMNS])
{
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}

static void add_matrices(const int a[][COLUMNS],
                         const int b[][COLUMNS],
                         int result[][COLUMNS])
{
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            result[row][column] = a[row][column] + b[row][column];
        }
    }
}

static void transpose(const int matrix[][COLUMNS],
                      int result[COLUMNS][ROWS])
{
    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            result[column][row] = matrix[row][column];
        }
    }
}

static void print_transpose(int matrix[COLUMNS][ROWS])
{
    for (size_t row = 0; row < COLUMNS; ++row) {
        for (size_t column = 0; column < ROWS; ++column) {
            printf("%d ", matrix[row][column]);
        }
        printf("\n");
    }
}

int main(void)
{
    const int a[ROWS][COLUMNS] = {{1, 2, 3}, {4, 5, 6}};
    const int b[ROWS][COLUMNS] = {{6, 5, 4}, {3, 2, 1}};
    int sum[ROWS][COLUMNS];
    int transposed[COLUMNS][ROWS];

    printf("A + B:\n");
    add_matrices(a, b, sum);
    print_matrix(sum);

    printf("\nTranspose of A:\n");
    transpose(a, transposed);
    print_transpose(transposed);

    return 0;
}
