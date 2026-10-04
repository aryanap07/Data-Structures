#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int sum = 0;

    for (int row = 0; row < 2; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            sum += matrix[row][column];
        }
    }

    printf("Sum of all elements = %d\n", sum);

    return 0;
}
