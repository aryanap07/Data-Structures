#include <stdio.h>

int main(void)
{
    int first = 10;
    int second = 20;
    int third = 30;

    int *pointers[] = {&first, &second, &third};

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *pointers[i]);
    }

    return 0;
}
