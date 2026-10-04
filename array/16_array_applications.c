/*
 * 16_array_applications.c
 * Topic: 3.16 - Applications of Arrays
 * Example applications: searching, finding maximum/minimum, and averaging.
 */

#include <stdio.h>

static int linear_search(const int array[], size_t length, int target)
{
    for (size_t i = 0; i < length; ++i) {
        if (array[i] == target) {
            return (int)i;
        }
    }

    return -1;
}

static int array_max(const int array[], size_t length)
{
    int maximum = array[0];

    for (size_t i = 1; i < length; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }

    return maximum;
}

static int array_min(const int array[], size_t length)
{
    int minimum = array[0];

    for (size_t i = 1; i < length; ++i) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }

    return minimum;
}

static double array_average(const int array[], size_t length)
{
    int sum = 0;

    for (size_t i = 0; i < length; ++i) {
        sum += array[i];
    }

    return (double)sum / (double)length;
}

int main(void)
{
    const int marks[] = {72, 85, 91, 68, 77, 88};
    const size_t length = sizeof(marks) / sizeof(marks[0]);
    const int target = 91;
    const int position = linear_search(marks, length, target);

    printf("Maximum : %d\n", array_max(marks, length));
    printf("Minimum : %d\n", array_min(marks, length));
    printf("Average : %.2f\n", array_average(marks, length));

    if (position >= 0) {
        printf("%d found at index %d\n", target, position);
    } else {
        printf("%d was not found\n", target);
    }

    return 0;
}
