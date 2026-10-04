#include <stdio.h>

#define N 5

int main(void)
{
    int graph[N][N] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[0][2] = 1;
    graph[2][0] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}
