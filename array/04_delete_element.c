/*
 * 04_delete_element.c
 * Topic: 3.5.3 - Deleting an Element from an Array
 */

#include <stdio.h>

static void print_array(const int array[], size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        printf("%d%s", array[i], (i + 1 == length) ? "\n" : " ");
    }
}

static int delete_at(int array[], size_t *length, size_t index)
{
    if (*length == 0 || index >= *length) {
        return 0;
    }

    for (size_t i = index; i + 1 < *length; ++i) {
        array[i] = array[i + 1];
    }

    --(*length);
    return 1;
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    size_t length = sizeof(numbers) / sizeof(numbers[0]);

    printf("Before deletion: ");
    print_array(numbers, length);

    if (!delete_at(numbers, &length, 2)) {
        printf("Deletion failed.\n");
        return 1;
    }

    printf("After deletion : ");
    print_array(numbers, length);

    return 0;
}
