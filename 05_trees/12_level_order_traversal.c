#include <stdio.h>

#define MAX 20

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void level_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *queue[MAX];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

int main(void)
{
    Node n4 = {4, NULL, NULL};
    Node n5 = {5, NULL, NULL};
    Node n2 = {2, &n4, &n5};
    Node n3 = {3, NULL, NULL};
    Node n1 = {1, &n2, &n3};

    level_order(&n1);
    printf("\n");

    return 0;
}
