#include <stdio.h>

#define N 6

void bfs(int graph[N][N], int start)
{
    int queue[N];
    int front = 0;
    int rear = 0;
    int visited[N] = {0};

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int u = queue[front++];

        printf("%d ", u);

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] && !visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    printf("\n");
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

    printf("BFS: ");
    bfs(graph, 0);

    return 0;
}
