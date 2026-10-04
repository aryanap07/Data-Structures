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

int find_key(BTreeNode *node, int value)
{
    int index = 0;

    while (index < node->count && node->keys[index] < value)
    {
        index++;
    }

    return index;
}

int get_predecessor(BTreeNode *node)
{
    while (!node->leaf)
    {
        node = node->children[node->count];
    }

    return node->keys[node->count - 1];
}

int get_successor(BTreeNode *node)
{
    while (!node->leaf)
    {
        node = node->children[0];
    }

    return node->keys[0];
}

void borrow_from_previous(BTreeNode *parent, int index)
{
    BTreeNode *child = parent->children[index];
    BTreeNode *sibling = parent->children[index - 1];

    for (int i = child->count - 1; i >= 0; i--)
    {
        child->keys[i + 1] = child->keys[i];
    }

    if (!child->leaf)
    {
        for (int i = child->count; i >= 0; i--)
        {
            child->children[i + 1] = child->children[i];
        }
    }

    child->keys[0] = parent->keys[index - 1];

    if (!child->leaf)
    {
        child->children[0] = sibling->children[sibling->count];
        sibling->children[sibling->count] = NULL;
    }

    parent->keys[index - 1] = sibling->keys[sibling->count - 1];

    child->count++;
    sibling->count--;
}

void borrow_from_next(BTreeNode *parent, int index)
{
    BTreeNode *child = parent->children[index];
    BTreeNode *sibling = parent->children[index + 1];

    child->keys[child->count] = parent->keys[index];

    if (!child->leaf)
    {
        child->children[child->count + 1] = sibling->children[0];
    }

    parent->keys[index] = sibling->keys[0];

    for (int i = 1; i < sibling->count; i++)
    {
        sibling->keys[i - 1] = sibling->keys[i];
    }

    if (!sibling->leaf)
    {
        for (int i = 1; i <= sibling->count; i++)
        {
            sibling->children[i - 1] = sibling->children[i];
        }

        sibling->children[sibling->count] = NULL;
    }

    child->count++;
    sibling->count--;
}

void merge_children(BTreeNode *parent, int index)
{
    BTreeNode *left = parent->children[index];
    BTreeNode *right = parent->children[index + 1];
    int left_keys = left->count;

    left->keys[left_keys] = parent->keys[index];

    for (int i = 0; i < right->count; i++)
    {
        left->keys[left_keys + 1 + i] = right->keys[i];
    }

    if (!left->leaf)
    {
        for (int i = 0; i <= right->count; i++)
        {
            left->children[left_keys + 1 + i] = right->children[i];
        }
    }

    left->count = left_keys + right->count + 1;

    for (int i = index + 1; i < parent->count; i++)
    {
        parent->keys[i - 1] = parent->keys[i];
    }

    for (int i = index + 2; i <= parent->count; i++)
    {
        parent->children[i - 1] = parent->children[i];
    }

    parent->children[parent->count] = NULL;
    parent->count--;

    free(right);
}

void fill_child(BTreeNode *parent, int index)
{
    if (index > 0 && parent->children[index - 1]->count >= T)
    {
        borrow_from_previous(parent, index);
    }
    else if (index < parent->count &&
             parent->children[index + 1]->count >= T)
    {
        borrow_from_next(parent, index);
    }
    else if (index < parent->count)
    {
        merge_children(parent, index);
    }
    else
    {
        merge_children(parent, index - 1);
    }
}

void delete_from_node(BTreeNode *node, int value)
{
    int index = find_key(node, value);

    if (index < node->count && node->keys[index] == value)
    {
        if (node->leaf)
        {
            for (int i = index + 1; i < node->count; i++)
            {
                node->keys[i - 1] = node->keys[i];
            }

            node->count--;
            return;
        }

        if (node->children[index]->count >= T)
        {
            int predecessor = get_predecessor(node->children[index]);
            node->keys[index] = predecessor;
            delete_from_node(node->children[index], predecessor);
        }
        else if (node->children[index + 1]->count >= T)
        {
            int successor = get_successor(node->children[index + 1]);
            node->keys[index] = successor;
            delete_from_node(node->children[index + 1], successor);
        }
        else
        {
            merge_children(node, index);
            delete_from_node(node->children[index], value);
        }

        return;
    }

    if (node->leaf)
    {
        return;
    }

    int last_child = index == node->count;

    if (node->children[index]->count < T)
    {
        fill_child(node, index);
    }

    if (last_child && index > node->count)
    {
        delete_from_node(node->children[index - 1], value);
    }
    else
    {
        delete_from_node(node->children[index], value);
    }
}

void delete_value(BTreeNode **root, int value)
{
    if (*root == NULL)
    {
        return;
    }

    delete_from_node(*root, value);

    if ((*root)->count == 0)
    {
        BTreeNode *old_root = *root;

        if (old_root->leaf)
        {
            *root = NULL;
        }
        else
        {
            *root = old_root->children[0];
        }

        free(old_root);
    }
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

    delete_value(&root, 6);
    delete_value(&root, 20);

    printf("After deletion: ");
    print_inorder(root);
    printf("\n");

    free_tree(root);

    return 0;
}
