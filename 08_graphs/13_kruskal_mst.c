#include <stdio.h>

#define N 5
#define M 7

typedef struct
{
    int u;
    int v;
    int weight;
} Edge;

int parent[N];
int rank_set[N];

void initialize_sets(void)
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        rank_set[i] = 0;
    }
}

int find(int value)
{
    if (parent[value] != value)
    {
        parent[value] = find(parent[value]);
    }

    return parent[value];
}

void union_sets(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a == b)
    {
        return;
    }

    if (rank_set[a] < rank_set[b])
    {
        parent[a] = b;
    }
    else if (rank_set[a] > rank_set[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[b] = a;
        rank_set[a]++;
    }
}

void sort_edges(Edge edges[M])
{
    for (int i = 0; i < M - 1; i++)
    {
        for (int j = 0; j < M - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void kruskal(Edge edges[M])
{
    initialize_sets();
    sort_edges(edges);

    int selected = 0;
    int total = 0;

    for (int i = 0; i < M && selected < N - 1; i++)
    {
        if (find(edges[i].u) != find(edges[i].v))
        {
            union_sets(edges[i].u, edges[i].v);

            printf("%d - %d: %d\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].weight);

            total += edges[i].weight;
            selected++;
        }
    }

    printf("MST weight: %d\n", total);
}

int main(void)
{
    Edge edges[M] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskal(edges);

    return 0;
}
