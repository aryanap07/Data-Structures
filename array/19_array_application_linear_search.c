#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 25, 30, 45, 50};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int target = 30;
    int found = 0;

    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == target)
        {
            printf("%d found at index %d.\n", target, i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("%d was not found.\n", target);
    }

    return 0;
}
