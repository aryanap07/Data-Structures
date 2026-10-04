#include <stdio.h>

#define MAX 20

typedef struct
{
    int id;
    int remaining;
} Process;

Process queue[MAX];
int front = 0;
int rear = 0;

void enqueue(Process process)
{
    queue[rear++] = process;
}

Process dequeue(void)
{
    return queue[front++];
}

int main(void)
{
    int quantum = 2;

    enqueue((Process){1, 5});
    enqueue((Process){2, 3});
    enqueue((Process){3, 4});

    while (front < rear)
    {
        Process process = dequeue();

        if (process.remaining > quantum)
        {
            printf("Process %d runs for %d units\n",
                   process.id,
                   quantum);

            process.remaining -= quantum;
            enqueue(process);
        }
        else
        {
            printf("Process %d runs for %d units and finishes\n",
                   process.id,
                   process.remaining);
        }
    }

    return 0;
}
