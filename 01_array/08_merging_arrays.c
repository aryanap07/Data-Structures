#include <stdio.h>

int main(void)
{
    int first[] = {10, 20, 30};
    int second[] = {40, 50, 60};
    int merged[6];

    int first_length = 3;
    int second_length = 3;

    for (int i = 0; i < first_length; i++)
    {
        merged[i] = first[i];
    }

    for (int i = 0; i < second_length; i++)
    {
        merged[first_length + i] = second[i];
    }

    printf("Merged array:\n");

    for (int i = 0; i < first_length + second_length; i++)
    {
        printf("%d ", merged[i]);
    }

    printf("\n");

    return 0;
}
