/*
 * 13_multidimensional_arrays.c
 * Topic: 3.13 - Multi-dimensional Arrays
 * Example: a 3-dimensional array.
 */

#include <stdio.h>

int main(void)
{
    int cube[2][2][3] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {7, 8, 9},
            {10, 11, 12}
        }
    };

    for (size_t layer = 0; layer < 2; ++layer) {
        printf("Layer %zu:\n", layer);
        for (size_t row = 0; row < 2; ++row) {
            for (size_t column = 0; column < 3; ++column) {
                printf("%d ", cube[layer][row][column]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
