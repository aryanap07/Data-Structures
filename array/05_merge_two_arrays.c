/*
 * 05_merge_two_arrays.c
 * Topic: 3.5.4 - Merging Two Arrays
 */

#include <stdio.h>

#define MAX_RESULT 20

static void print_array(const int array[], size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        printf("%d%s", array[i], (i + 1 == length) ? "\n" : " ");
    }
}

static size_t merge_arrays(const int first[], size_t first_length,
                           const int second[], size_t second_length,
                           int result[], size_t result_capacity)
{
    if (first_length + second_length > result_capacity) {
        return 0;
    }

    for (size_t i = 0; i < first_length; ++i) {
        result[i] = first[i];
    }

    for (size_t i = 0; i < second_length; ++i) {
        result[first_length + i] = second[i];
    }

    return first_length + second_length;
}

int main(void)
{
    const int first[] = {1, 3, 5, 7};
    const int second[] = {2, 4, 6, 8};
    int merged[MAX_RESULT];

    size_t first_length = sizeof(first) / sizeof(first[0]);
    size_t second_length = sizeof(second) / sizeof(second[0]);

    size_t merged_length = merge_arrays(first, first_length,
                                        second, second_length,
                                        merged, MAX_RESULT);

    if (merged_length == 0) {
        printf("Merge failed: result capacity is too small.\n");
        return 1;
    }

    printf("Merged array: ");
    print_array(merged, merged_length);

    return 0;
}
