#include <stdio.h>
#include <stdlib.h>

#define T 2
#define MAX_KEYS (2 * T - 1)
#define MAX_CHILDREN (2 * T)

typedef struct BTreeNode
{
    int keys[MAX_KEYS];
    struct BTreeNode *children[MAX_CHILDREN];
    int count;
    int leaf;
} BTreeNode;

BTreeNode *create_node(int leaf)
{
    BTreeNode *node = malloc(sizeof(BTreeNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->count = 0;
    node->leaf = leaf;

    for (int i = 0; i < MAX_CHILDREN; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

BTreeNode *search(BTreeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    int i = 0;

    while (i < root->count && value > root->keys[i])
    {
        i++;
    }

    if (i < root->count && value == root->keys[i])
    {
        return root;
    }

    if (root->leaf)
    {
        return NULL;
    }

    return search(root->children[i], value);
}

void free_tree(BTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    if (!root->leaf)
    {
        for (int i = 0; i <= root->count; i++)
        {
            free_tree(root->children[i]);
        }
    }

    free(root);
}

int main(void)
{
    BTreeNode *root = create_node(1);

    if (root == NULL)
    {
        return 1;
    }

    root->count = 3;
    root->keys[0] = 10;
    root->keys[1] = 20;
    root->keys[2] = 30;

    printf("Search 20: %s\n",
           search(root, 20) != NULL ? "Found" : "Not found");

    printf("Search 25: %s\n",
           search(root, 25) != NULL ? "Found" : "Not found");

    free_tree(root);

    return 0;
}
