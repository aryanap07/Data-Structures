#include <stdio.h>

#define N 4

void transitive_closure(int graph[N][N])
{
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                graph[i][j] = graph[i][j] ||
                              (graph[i][k] && graph[k][j]);
            }
        }
    }
}

void print_matrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    int graph[N][N] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    transitive_closure(graph);

    print_matrix(graph);

    return 0;
}
