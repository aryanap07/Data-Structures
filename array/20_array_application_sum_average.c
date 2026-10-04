#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }

    double average = (double)sum / length;

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
