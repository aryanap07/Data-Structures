#include <stdio.h>

#define SIZE 10

int hash(int key)
{
    const double factor = 0.6180339887;
    double value = key * factor;
    double fraction = value - (int)value;

    if (fraction < 0)
    {
        fraction += 1.0;
    }

    return (int)(SIZE * fraction);
}

int main(void)
{
    int keys[] = {12, 25, 37, 49, 58};
    int length = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < length; i++)
    {
        printf("Key %d -> index %d\n", keys[i], hash(keys[i]));
    }

    return 0;
}
