/*
 * 01_basic_arrays.c
 * Topics: 3.1-3.4
 * Declaration, initialization, access, address calculation, length, storage.
 */

#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Array length: %zu\n\n", length);

    printf("Elements:\n");
    for (size_t i = 0; i < length; ++i) {
        printf("numbers[%zu] = %d\n", i, numbers[i]);
    }

    printf("\nAddress calculation:\n");
    printf("Base address      : %p\n", (void *)numbers);
    printf("Address of [2]     : %p\n", (void *)&numbers[2]);
    printf("Computed address   : %p\n", (void *)(numbers + 2));
    printf("Element [2]        : %d\n", *(numbers + 2));

    return 0;
}
