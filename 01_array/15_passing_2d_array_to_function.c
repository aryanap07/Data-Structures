#include <stdio.h>

void print_matrix(int matrix[][3], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf("%d ", matrix[row][column]);
        }

        printf("\n");
    }
}

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    print_matrix(matrix, 2);

    return 0;
}
