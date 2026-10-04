#include <stdio.h>

int main(void)
{
    int graph[4][4] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    printf("Directed edges:\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (graph[i][j])
            {
                printf("%d -> %d\n", i, j);
            }
        }
    }

    return 0;
}
