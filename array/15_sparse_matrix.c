/*
 * 15_sparse_matrix.c
 * Topic: 3.15 - Sparse Matrices
 * Stores only non-zero values using triplet representation: row, column, value.
 */

#include <stdio.h>

#define ROWS 4
#define COLUMNS 5
#define MAX_NON_ZERO 20

typedef struct {
    size_t row;
    size_t column;
    int value;
} NonZeroElement;

static size_t to_triplet(const int matrix[ROWS][COLUMNS],
                         NonZeroElement triplets[], size_t capacity)
{
    size_t count = 0;

    for (size_t row = 0; row < ROWS; ++row) {
        for (size_t column = 0; column < COLUMNS; ++column) {
            if (matrix[row][column] != 0) {
                if (count >= capacity) {
                    return 0;
                }

                triplets[count++] = (NonZeroElement){
                    row, column, matrix[row][column]
                };
            }
        }
    }

    return count;
}

int main(void)
{
    const int matrix[ROWS][COLUMNS] = {
        {0, 0, 3, 0, 0},
        {0, 4, 0, 0, 0},
        {0, 0, 0, 0, 5},
        {2, 0, 0, 0, 0}
    };

    NonZeroElement triplets[MAX_NON_ZERO];
    size_t count = to_triplet(matrix, triplets, MAX_NON_ZERO);

    printf("Sparse matrix in triplet form:\n");
    printf("Row  Column  Value\n");
    printf("------------------\n");

    for (size_t i = 0; i < count; ++i) {
        printf("%-4zu %-7zu %d\n",
               triplets[i].row,
               triplets[i].column,
               triplets[i].value);
    }

    return 0;
}
