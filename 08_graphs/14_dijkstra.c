#include <stdio.h>
#include <limits.h>

#define N 5

int min_distance(int distance[N], int visited[N])
{
    int minimum = INT_MAX;
    int index = -1;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && distance[i] < minimum)
        {
            minimum = distance[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int graph[N][N], int source)
{
    int distance[N];
    int visited[N] = {0};

    for (int i = 0; i < N; i++)
    {
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    for (int count = 0; count < N; count++)
    {
        int u = min_distance(distance, visited);

        if (u == -1)
        {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < N; v++)
        {
            if (!visited[v] &&
                graph[u][v] > 0 &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (distance[i] == INT_MAX)
        {
            printf("%d: INF\n", i);
        }
        else
        {
            printf("%d: %d\n", i, distance[i]);
        }
    }
}

int main(void)
{
    int graph[N][N] = {
        {0, 10, 3, 0, 0},
        {0, 0, 1, 2, 0},
        {0, 4, 0, 8, 2},
        {0, 0, 0, 0, 7},
        {0, 0, 0, 9, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
