#include <stdio.h>

int main(void)
{
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("Base address: %p\n", (void *)numbers);
    printf("Address of numbers[2]: %p\n", (void *)&numbers[2]);

    printf("Number of elements: %zu\n", sizeof(numbers) / sizeof(numbers[0]));
    printf("Size of one element: %zu bytes\n", sizeof(numbers[0]));
    printf("Total array size: %zu bytes\n", sizeof(numbers));

    return 0;
}
