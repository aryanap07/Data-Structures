/*
 * 02_traversing_array.c
 * Topic: 3.5.1 - Traversing an Array
 */

#include <stdio.h>

int main(void)
{
    int numbers[] = {12, 7, 25, 9, 18, 4};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Forward traversal: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Reverse traversal: ");
    for (size_t i = length; i-- > 0;) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
