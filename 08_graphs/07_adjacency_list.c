#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

#define N 5

void add_edge(Node *graph[N], int u, int v)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return;
    }

    node->vertex = v;
    node->next = graph[u];
    graph[u] = node;
}

void print_graph(Node *graph[N])
{
    for (int i = 0; i < N; i++)
    {
        printf("%d: ", i);

        Node *current = graph[i];

        while (current != NULL)
        {
            printf("%d -> ", current->vertex);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void free_graph(Node *graph[N])
{
    for (int i = 0; i < N; i++)
    {
        while (graph[i] != NULL)
        {
            Node *next = graph[i]->next;
            free(graph[i]);
            graph[i] = next;
        }
    }
}

int main(void)
{
    Node *graph[N] = {NULL};

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    print_graph(graph);
    free_graph(graph);

    return 0;
}
