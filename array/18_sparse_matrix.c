#include <stdio.h>

int main(void)
{
    int matrix[3][3] = {
        {0, 0, 5},
        {0, 0, 0},
        {2, 0, 0}
    };

    int rows = 3;
    int columns = 3;
    int zero_count = 0;
    int total_elements = rows * columns;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix[row][column] == 0)
            {
                zero_count++;
            }
        }
    }

    printf("Zero elements = %d\n", zero_count);
    printf("Total elements = %d\n", total_elements);

    if (zero_count > total_elements / 2)
    {
        printf("This is a sparse matrix.\n");
    }
    else
    {
        printf("This is not a sparse matrix.\n");
    }

    return 0;
}
