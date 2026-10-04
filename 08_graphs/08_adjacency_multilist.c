#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int u;
    int v;
    struct Edge *next_u;
    struct Edge *next_v;
} Edge;

typedef struct
{
    Edge *first;
} Vertex;

Edge *create_edge(int u, int v)
{
    Edge *edge = malloc(sizeof(Edge));

    if (edge != NULL)
    {
        edge->u = u;
        edge->v = v;
        edge->next_u = NULL;
        edge->next_v = NULL;
    }

    return edge;
}

void add_edge(Vertex graph[], int u, int v)
{
    Edge *edge = create_edge(u, v);

    if (edge == NULL)
    {
        return;
    }

    edge->next_u = graph[u].first;
    graph[u].first = edge;

    edge->next_v = graph[v].first;
    graph[v].first = edge;
}

void print_edges(Vertex graph[], int vertices)
{
    int printed[20][20] = {0};

    for (int u = 0; u < vertices; u++)
    {
        Edge *edge = graph[u].first;

        while (edge != NULL)
        {
            int v = edge->u == u ? edge->v : edge->u;

            if (!printed[u][v])
            {
                printf("%d -- %d\n", u, v);
                printed[u][v] = 1;
                printed[v][u] = 1;
            }

            edge = edge->u == u ? edge->next_u : edge->next_v;
        }
    }
}

void free_graph(Vertex graph[], int vertices)
{
    int seen[20][20] = {0};

    for (int u = 0; u < vertices; u++)
    {
        Edge *edge = graph[u].first;

        while (edge != NULL)
        {
            int v = edge->u == u ? edge->v : edge->u;

            if (!seen[u][v])
            {
                free(edge);
                seen[u][v] = 1;
                seen[v][u] = 1;
            }

            edge = edge->u == u ? edge->next_u : edge->next_v;
        }

        graph[u].first = NULL;
    }
}

int main(void)
{
    Vertex graph[5] = {0};

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    print_edges(graph, 5);
    free_graph(graph, 5);

    return 0;
}
