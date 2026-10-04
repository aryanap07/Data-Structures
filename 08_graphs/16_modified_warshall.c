#include <stdio.h>

#define N 4
#define INF 9999

void modified_warshall(int distance[N][N])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (distance[i][k] != INF &&
                    distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] =
                        distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

int main(void)
{
    int distance[N][N] = {
        {0, 5, 9, INF},
        {INF, 0, 2, 8},
        {INF, INF, 0, 3},
        {INF, INF, INF, 0}
    };

    modified_warshall(distance);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (distance[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ", distance[i][j]);
            }
        }

        printf("\n");
    }

    return 0;
}
