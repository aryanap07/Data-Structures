#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    char symbol;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(char symbol, int frequency)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        return NULL;
    }

    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_sorted(Node *array[], int *size, Node *node)
{
    int i = *size;

    while (i > 0 && array[i - 1]->frequency > node->frequency)
    {
        array[i] = array[i - 1];
        i--;
    }

    array[i] = node;
    (*size)++;
}

Node *remove_first(Node *array[], int *size)
{
    Node *node = array[0];

    for (int i = 1; i < *size; i++)
    {
        array[i - 1] = array[i];
    }

    (*size)--;

    return node;
}

void print_codes(Node *root, char code[], int length)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        code[length] = '\0';
        printf("%c: %s\n", root->symbol, code);
        return;
    }

    code[length] = '0';
    print_codes(root->left, code, length + 1);

    code[length] = '1';
    print_codes(root->right, code, length + 1);
}

void free_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    Node *nodes[MAX];
    int size = 0;
    char symbols[] = {'A', 'B', 'C', 'D'};
    int frequencies[] = {5, 9, 12, 13};

    for (int i = 0; i < 4; i++)
    {
        Node *node = create_node(symbols[i], frequencies[i]);

        if (node == NULL)
        {
            for (int j = 0; j < size; j++)
            {
                free_tree(nodes[j]);
            }

            return 1;
        }

        insert_sorted(nodes, &size, node);
    }

    while (size > 1)
    {
        Node *first = remove_first(nodes, &size);
        Node *second = remove_first(nodes, &size);
        Node *parent = create_node(
            '#',
            first->frequency + second->frequency
        );

        if (parent == NULL)
        {
            free_tree(first);
            free_tree(second);

            for (int i = 0; i < size; i++)
            {
                free_tree(nodes[i]);
            }

            return 1;
        }

        parent->left = first;
        parent->right = second;

        insert_sorted(nodes, &size, parent);
    }

    char code[MAX];
    printf("Huffman codes:\n");
    print_codes(nodes[0], code, 0);

    free_tree(nodes[0]);

    return 0;
}
