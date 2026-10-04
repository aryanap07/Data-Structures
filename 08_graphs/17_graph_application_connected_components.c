#include <stdio.h>

#define N 7

void dfs(int graph[N][N], int visited[N], int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < N; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

int main(void)
{
    int graph[N][N] = {0};
    int visited[N] = {0};

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[5][6] = graph[6][5] = 1;

    int components = 0;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            components++;
            printf("Component %d: ", components);
            dfs(graph, visited, i);
            printf("\n");
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}
