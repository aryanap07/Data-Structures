/*
 * 06_pass_arrays_to_functions.c
 * Topics: 3.6, 3.6.1, 3.6.2
 * Passing individual elements and an entire array to functions.
 */

#include <stdio.h>

static void print_element(int value)
{
    printf("Individual element: %d\n", value);
}

static void print_array(const int array[], size_t length)
{
    printf("Entire array: ");
    for (size_t i = 0; i < length; ++i) {
        printf("%d%s", array[i], (i + 1 == length) ? "\n" : " ");
    }
}

static int array_sum(const int array[], size_t length)
{
    int sum = 0;

    for (size_t i = 0; i < length; ++i) {
        sum += array[i];
    }

    return sum;
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    print_element(numbers[1]);
    print_array(numbers, length);
    printf("Sum: %d\n", array_sum(numbers, length));

    return 0;
}
