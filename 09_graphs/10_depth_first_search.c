#include <stdio.h>

#define N 6

void dfs(int graph[N][N], int visited[N], int u)
{
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < N; v++)
    {
        if (graph[u][v] && !visited[v])
        {
            dfs(graph, visited, v);
        }
    }
}

int main(void)
{
    int graph[N][N] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0}
    };

    int visited[N] = {0};

    printf("DFS: ");
    dfs(graph, visited, 0);
    printf("\n");

    return 0;
}
