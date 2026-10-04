/*
 * 03_insert_element.c
 * Topic: 3.5.2 - Inserting an Element in an Array
 */

#include <stdio.h>

#define CAPACITY 10

static void print_array(const int array[], size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        printf("%d%s", array[i], (i + 1 == length) ? "\n" : " ");
    }
}

static int insert_at(int array[], size_t *length, size_t index, int value)
{
    if (*length >= CAPACITY || index > *length) {
        return 0;
    }

    for (size_t i = *length; i > index; --i) {
        array[i] = array[i - 1];
    }

    array[index] = value;
    ++(*length);
    return 1;
}

int main(void)
{
    int numbers[CAPACITY] = {10, 20, 30, 40, 50};
    size_t length = 5;

    printf("Before insertion: ");
    print_array(numbers, length);

    if (!insert_at(numbers, &length, 2, 99)) {
        printf("Insertion failed.\n");
        return 1;
    }

    printf("After insertion : ");
    print_array(numbers, length);

    return 0;
}
