#include <stdio.h>

#define MAX 10

int graph[5][5] =
{
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int queue[MAX];
int front = 0;
int rear = 0;
int visited[5] = {0};

void enqueue(int value)
{
    queue[rear++] = value;
}

int dequeue(void)
{
    return queue[front++];
}

int main(void)
{
    int start = 0;

    visited[start] = 1;
    enqueue(start);

    printf("BFS: ");

    while (front < rear)
    {
        int current = dequeue();

        printf("%d ", current);

        for (int i = 0; i < 5; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    printf("\n");

    return 0;
}
