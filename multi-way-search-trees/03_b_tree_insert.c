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

void split_child(BTreeNode *parent, int index)
{
    BTreeNode *full = parent->children[index];
    BTreeNode *right = create_node(full->leaf);

    if (right == NULL)
    {
        return;
    }

    right->count = T - 1;

    for (int i = 0; i < T - 1; i++)
    {
        right->keys[i] = full->keys[i + T];
    }

    if (!full->leaf)
    {
        for (int i = 0; i < T; i++)
        {
            right->children[i] = full->children[i + T];
            full->children[i + T] = NULL;
        }
    }

    full->count = T - 1;

    for (int i = parent->count; i >= index + 1; i--)
    {
        parent->children[i + 1] = parent->children[i];
    }

    parent->children[index + 1] = right;

    for (int i = parent->count - 1; i >= index; i--)
    {
        parent->keys[i + 1] = parent->keys[i];
    }

    parent->keys[index] = full->keys[T - 1];
    parent->count++;
}

void insert_non_full(BTreeNode *node, int value)
{
    int i = node->count - 1;

    if (node->leaf)
    {
        while (i >= 0 && value < node->keys[i])
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        if (i >= 0 && value == node->keys[i])
        {
            return;
        }

        node->keys[i + 1] = value;
        node->count++;
        return;
    }

    while (i >= 0 && value < node->keys[i])
    {
        i--;
    }

    i++;

    if (i < node->count && value == node->keys[i])
    {
        return;
    }

    if (node->children[i]->count == MAX_KEYS)
    {
        split_child(node, i);

        if (value > node->keys[i])
        {
            i++;
        }
        else if (value == node->keys[i])
        {
            return;
        }
    }

    insert_non_full(node->children[i], value);
}

void insert(BTreeNode **root, int value)
{
    if (*root == NULL)
    {
        *root = create_node(1);

        if (*root != NULL)
        {
            (*root)->keys[0] = value;
            (*root)->count = 1;
        }

        return;
    }

    if ((*root)->count == MAX_KEYS)
    {
        BTreeNode *new_root = create_node(0);

        if (new_root == NULL)
        {
            return;
        }

        new_root->children[0] = *root;
        split_child(new_root, 0);

        if (value == new_root->keys[0])
        {
            free(new_root);
            return;
        }

        int index = value > new_root->keys[0] ? 1 : 0;
        insert_non_full(new_root->children[index], value);
        *root = new_root;
        return;
    }

    insert_non_full(*root, value);
}

void print_inorder(BTreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->count; i++)
    {
        if (!root->leaf)
        {
            print_inorder(root->children[i]);
        }

        printf("%d ", root->keys[i]);
    }

    if (!root->leaf)
    {
        print_inorder(root->children[root->count]);
    }
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
    int values[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int length = sizeof(values) / sizeof(values[0]);
    BTreeNode *root = NULL;

    for (int i = 0; i < length; i++)
    {
        insert(&root, values[i]);
    }

    printf("B-tree inorder: ");
    print_inorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}
