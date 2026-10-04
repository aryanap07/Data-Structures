#include <stdio.h>

int maximum(const int array[], int length)
{
    int maximum_value = array[0];

    for (int i = 1; i < length; i++)
    {
        if (array[i] > maximum_value)
        {
            maximum_value = array[i];
        }
    }

    return maximum_value;
}

void counting_sort(int array[], int length, int place)
{
    int output[length];
    int count[10] = {0};

    for (int i = 0; i < length; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = (array[i] / place) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    for (int i = 0; i < length; i++)
    {
        array[i] = output[i];
    }
}

void radix_sort(int array[], int length)
{
    int max_value = maximum(array, length);

    for (int place = 1; max_value / place > 0; place *= 10)
    {
        counting_sort(array, length, place);
    }
}

int main(void)
{
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int length = sizeof(array) / sizeof(array[0]);

    radix_sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
