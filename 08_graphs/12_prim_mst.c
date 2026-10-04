#include <stdio.h>
#include <limits.h>

#define N 5

int min_key(int key[N], int in_mst[N])
{
    int minimum = INT_MAX;
    int index = -1;

    for (int v = 0; v < N; v++)
    {
        if (!in_mst[v] && key[v] < minimum)
        {
            minimum = key[v];
            index = v;
        }
    }

    return index;
}

void prim(int graph[N][N])
{
    int parent[N];
    int key[N];
    int in_mst[N] = {0};

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < N; count++)
    {
        int u = min_key(key, in_mst);

        if (u == -1)
        {
            return;
        }

        in_mst[u] = 1;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] &&
                !in_mst[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    for (int v = 1; v < N; v++)
    {
        printf("%d - %d: %d\n",
               parent[v],
               v,
               graph[parent[v]][v]);

        total += graph[parent[v]][v];
    }

    printf("MST weight: %d\n", total);
}

int main(void)
{
    int graph[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph);

    return 0;
}
