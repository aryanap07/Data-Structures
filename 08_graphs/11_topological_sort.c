#include <stdio.h>

#define N 6

void topological_sort(int graph[N][N])
{
    int indegree[N] = {0};
    int queue[N];
    int front = 0;
    int rear = 0;
    int count = 0;

    for (int u = 0; u < N; u++)
    {
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v])
            {
                indegree[v]++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            queue[rear++] = i;
        }
    }

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v])
            {
                indegree[v]--;

                if (indegree[v] == 0)
                {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != N)
    {
        printf("\nGraph contains a cycle");
    }

    printf("\n");
}

int main(void)
{
    int graph[N][N] = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Topological order: ");
    topological_sort(graph);

    return 0;
}
