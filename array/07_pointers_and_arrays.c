/*
 * 07_pointers_and_arrays.c
 * Topic: 3.7 - Pointers and Arrays
 */

#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40};
    int *pointer = numbers;
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Using array indexing:\n");
    for (size_t i = 0; i < length; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    printf("Using pointer arithmetic:\n");
    for (size_t i = 0; i < length; ++i) {
        printf("%d ", *(pointer + i));
    }
    printf("\n\n");

    printf("Array address : %p\n", (void *)numbers);
    printf("Pointer value : %p\n", (void *)pointer);
    printf("First element : %d\n", *pointer);

    return 0;
}
