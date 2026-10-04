#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int row = 0; row < 2; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf("%d ", matrix[row][column]);
        }

        printf("\n");
    }

    return 0;
}
