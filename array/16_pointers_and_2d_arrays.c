#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int (*ptr)[3] = matrix;

    printf("First element: %d\n", ptr[0][0]);
    printf("Element at row 2, column 3: %d\n", ptr[1][2]);

    return 0;
}
