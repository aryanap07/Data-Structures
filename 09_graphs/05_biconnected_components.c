#include <stdio.h>

#define N 7
#define M 9

typedef struct
{
    int u;
    int v;
} Edge;

int graph[N][N];
int discovery[N];
int low[N];
int parent[N];
int time_counter;
Edge edge_stack[M];
int edge_top;

void add_edge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void print_component(int stop_u, int stop_v)
{
    printf("Biconnected component: ");

    while (edge_top > 0)
    {
        Edge edge = edge_stack[--edge_top];

        printf("(%d,%d) ", edge.u, edge.v);

        if (edge.u == stop_u && edge.v == stop_v)
        {
            break;
        }
    }

    printf("\n");
}

void dfs(int u)
{
    discovery[u] = low[u] = ++time_counter;

    for (int v = 0; v < N; v++)
    {
        if (!graph[u][v])
        {
            continue;
        }

        if (discovery[v] == 0)
        {
            parent[v] = u;
            edge_stack[edge_top++] = (Edge){u, v};

            dfs(v);

            if (low[v] < low[u])
            {
                low[u] = low[v];
            }

            if (low[v] >= discovery[u])
            {
                print_component(u, v);
            }
        }
        else if (v != parent[u] && discovery[v] < discovery[u])
        {
            edge_stack[edge_top++] = (Edge){u, v};

            if (discovery[v] < low[u])
            {
                low[u] = discovery[v];
            }
        }
    }
}

int main(void)
{
    add_edge(0, 1);
    add_edge(1, 2);
    add_edge(2, 0);
    add_edge(1, 3);
    add_edge(3, 4);
    add_edge(4, 5);
    add_edge(5, 3);
    add_edge(4, 6);
    add_edge(5, 6);

    for (int i = 0; i < N; i++)
    {
        parent[i] = -1;
    }

    for (int i = 0; i < N; i++)
    {
        if (discovery[i] == 0)
        {
            dfs(i);
        }
    }

    return 0;
}
