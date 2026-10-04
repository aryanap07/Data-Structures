/*
 * 08_array_of_pointers.c
 * Topic: 3.8 - Arrays of Pointers
 */

#include <stdio.h>

int main(void)
{
    int first = 10;
    int second = 20;
    int third = 30;

    int *values[] = {&first, &second, &third};
    size_t length = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < length; ++i) {
        printf("values[%zu] -> %d\n", i, *values[i]);
    }

    *values[1] = 99;
    printf("\nAfter modifying through pointer:\n");
    printf("second = %d\n", second);

    return 0;
}
