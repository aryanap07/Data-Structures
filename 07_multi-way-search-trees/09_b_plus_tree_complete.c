#include <stdio.h>
#include <stdlib.h>

#define ORDER 4
#define MAX_KEYS (ORDER - 1)
#define MIN_LEAF_KEYS 1
#define MIN_INTERNAL_KEYS 1

typedef struct BPlusNode
{
    int keys[ORDER];
    int count;
    int leaf;
    struct BPlusNode *children[ORDER + 1];
    struct BPlusNode *next;
} BPlusNode;

BPlusNode *create_node(int leaf)
{
    BPlusNode *node = malloc(sizeof(BPlusNode));

    if (node == NULL)
    {
        return NULL;
    }

    node->count = 0;
    node->leaf = leaf;
    node->next = NULL;

    for (int i = 0; i < ORDER + 1; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

int first_key(BPlusNode *node)
{
    while (node != NULL && !node->leaf)
    {
        node = node->children[0];
    }

    return node->keys[0];
}

void update_keys(BPlusNode *node)
{
    if (node == NULL || node->leaf)
    {
        return;
    }

    for (int i = 0; i <= node->count; i++)
    {
        update_keys(node->children[i]);
    }

    for (int i = 0; i < node->count; i++)
    {
        node->keys[i] = first_key(node->children[i + 1]);
    }
}

BPlusNode *find_leaf(BPlusNode *root, int value)
{
    while (root != NULL && !root->leaf)
    {
        int i = 0;

        while (i < root->count && value >= root->keys[i])
        {
            i++;
        }

        root = root->children[i];
    }

    return root;
}

int search(BPlusNode *root, int value)
{
    BPlusNode *leaf = find_leaf(root, value);

    if (leaf == NULL)
    {
        return 0;
    }

    for (int i = 0; i < leaf->count; i++)
    {
        if (leaf->keys[i] == value)
        {
            return 1;
        }
    }

    return 0;
}

int split_leaf(BPlusNode *leaf, BPlusNode **right_node)
{
    BPlusNode *right = create_node(1);

    if (right == NULL)
    {
        return 0;
    }

    int split = (MAX_KEYS + 1) / 2;

    right->count = MAX_KEYS + 1 - split;

    for (int i = 0; i < right->count; i++)
    {
        right->keys[i] = leaf->keys[split + i];
    }

    leaf->count = split;

    right->next = leaf->next;
    leaf->next = right;

    *right_node = right;
    return right->keys[0];
}

int split_internal(BPlusNode *node, BPlusNode **right_node)
{
    BPlusNode *right = create_node(0);

    if (right == NULL)
    {
        return 0;
    }

    int promote = node->keys[2];

    right->count = 1;
    right->keys[0] = node->keys[3];
    right->children[0] = node->children[3];
    right->children[1] = node->children[4];

    node->children[3] = NULL;
    node->children[4] = NULL;
    node->count = 2;

    *right_node = right;
    return promote;
}

int insert_recursive(
    BPlusNode *node,
    int value,
    int *separator,
    BPlusNode **right_node)
{
    if (node->leaf)
    {
        int i = node->count - 1;

        while (i >= 0 && value < node->keys[i])
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = value;
        node->count++;

        if (node->count <= MAX_KEYS)
        {
            return 0;
        }

        *separator = split_leaf(node, right_node);
        return 1;
    }

    int index = 0;

    while (index < node->count && value >= node->keys[index])
    {
        index++;
    }

    int child_separator;
    BPlusNode *child_right = NULL;

    if (!insert_recursive(
            node->children[index],
            value,
            &child_separator,
            &child_right))
    {
        return 0;
    }

    for (int i = node->count; i > index; i--)
    {
        node->keys[i] = node->keys[i - 1];
    }

    for (int i = node->count + 1; i > index + 1; i--)
    {
        node->children[i] = node->children[i - 1];
    }

    node->keys[index] = child_separator;
    node->children[index + 1] = child_right;
    node->count++;

    if (node->count <= MAX_KEYS)
    {
        return 0;
    }

    *separator = split_internal(node, right_node);
    return 1;
}

int insert(BPlusNode **root, int value)
{
    if (*root == NULL)
    {
        *root = create_node(1);

        if (*root == NULL)
        {
            return 0;
        }

        (*root)->keys[0] = value;
        (*root)->count = 1;
        return 1;
    }

    if (search(*root, value))
    {
        return 0;
    }

    int separator;
    BPlusNode *right_node = NULL;

    if (!insert_recursive(*root, value, &separator, &right_node))
    {
        update_keys(*root);
        return 1;
    }

    BPlusNode *new_root = create_node(0);

    if (new_root == NULL)
    {
        return 0;
    }

    new_root->keys[0] = separator;
    new_root->count = 1;
    new_root->children[0] = *root;
    new_root->children[1] = right_node;

    *root = new_root;
    update_keys(*root);

    return 1;
}

void remove_parent_child(BPlusNode *parent, int index)
{
    for (int i = index + 1; i <= parent->count; i++)
    {
        parent->children[i - 1] = parent->children[i];
    }

    parent->children[parent->count] = NULL;
    parent->count--;
}

void borrow_leaf_from_left(BPlusNode *parent, int index)
{
    BPlusNode *left = parent->children[index - 1];
    BPlusNode *child = parent->children[index];

    for (int i = child->count; i > 0; i--)
    {
        child->keys[i] = child->keys[i - 1];
    }

    child->keys[0] = left->keys[left->count - 1];
    child->count++;
    left->count--;
}

void borrow_leaf_from_right(BPlusNode *parent, int index)
{
    BPlusNode *child = parent->children[index];
    BPlusNode *right = parent->children[index + 1];

    child->keys[child->count] = right->keys[0];
    child->count++;

    for (int i = 1; i < right->count; i++)
    {
        right->keys[i - 1] = right->keys[i];
    }

    right->count--;
}

void merge_leaves(BPlusNode *parent, int index)
{
    BPlusNode *left = parent->children[index];
    BPlusNode *right = parent->children[index + 1];

    for (int i = 0; i < right->count; i++)
    {
        left->keys[left->count + i] = right->keys[i];
    }

    left->count += right->count;
    left->next = right->next;

    remove_parent_child(parent, index + 1);
    free(right);
}

int internal_child_count(BPlusNode *node)
{
    return node->count + 1;
}

void borrow_internal_from_left(BPlusNode *parent, int index)
{
    BPlusNode *left = parent->children[index - 1];
    BPlusNode *child = parent->children[index];

    for (int i = child->count + 1; i > 0; i--)
    {
        child->children[i] = child->children[i - 1];
    }

    child->children[0] = left->children[left->count];
    child->count++;
    left->children[left->count] = NULL;
    left->count--;
}

void borrow_internal_from_right(BPlusNode *parent, int index)
{
    BPlusNode *child = parent->children[index];
    BPlusNode *right = parent->children[index + 1];

    child->children[child->count + 1] = right->children[0];
    child->count++;

    for (int i = 1; i <= right->count; i++)
    {
        right->children[i - 1] = right->children[i];
    }

    right->children[right->count] = NULL;
    right->count--;
}

void merge_internal(BPlusNode *parent, int index)
{
    BPlusNode *left = parent->children[index];
    BPlusNode *right = parent->children[index + 1];
    int offset = left->count + 1;

    for (int i = 0; i <= right->count; i++)
    {
        left->children[offset + i] = right->children[i];
    }

    left->count = left->count + right->count + 1;

    remove_parent_child(parent, index + 1);
    free(right);
}

void rebalance_child(BPlusNode *parent, int index)
{
    BPlusNode *child = parent->children[index];

    if (child->leaf)
    {
        if (index > 0 &&
            parent->children[index - 1]->count > MIN_LEAF_KEYS)
        {
            borrow_leaf_from_left(parent, index);
        }
        else if (index < parent->count &&
                 parent->children[index + 1]->count > MIN_LEAF_KEYS)
        {
            borrow_leaf_from_right(parent, index);
        }
        else if (index < parent->count)
        {
            merge_leaves(parent, index);
        }
        else
        {
            merge_leaves(parent, index - 1);
        }

        return;
    }

    if (index > 0 &&
        internal_child_count(parent->children[index - 1]) >
            MIN_INTERNAL_KEYS + 1)
    {
        borrow_internal_from_left(parent, index);
    }
    else if (index < parent->count &&
             internal_child_count(parent->children[index + 1]) >
                 MIN_INTERNAL_KEYS + 1)
    {
        borrow_internal_from_right(parent, index);
    }
    else if (index < parent->count)
    {
        merge_internal(parent, index);
    }
    else
    {
        merge_internal(parent, index - 1);
    }
}

int delete_recursive(BPlusNode *node, int value, int is_root)
{
    if (node->leaf)
    {
        int index = 0;

        while (index < node->count && node->keys[index] != value)
        {
            index++;
        }

        if (index == node->count)
        {
            return 0;
        }

        for (int i = index + 1; i < node->count; i++)
        {
            node->keys[i - 1] = node->keys[i];
        }

        node->count--;

        if (!is_root && node->count < MIN_LEAF_KEYS)
        {
            return 1;
        }

        return 0;
    }

    int index = 0;

    while (index < node->count && value >= node->keys[index])
    {
        index++;
    }

    if (!delete_recursive(node->children[index], value, 0))
    {
        update_keys(node);
        return 0;
    }

    if (node->children[index]->leaf)
    {
        if (node->children[index]->count < MIN_LEAF_KEYS)
        {
            rebalance_child(node, index);
        }
    }
    else if (node->children[index]->count < MIN_INTERNAL_KEYS)
    {
        rebalance_child(node, index);
    }

    update_keys(node);

    if (!is_root && node->count < MIN_INTERNAL_KEYS)
    {
        return 1;
    }

    return 0;
}

int delete_value(BPlusNode **root, int value)
{
    if (*root == NULL || !search(*root, value))
    {
        return 0;
    }

    delete_recursive(*root, value, 1);

    if (!(*root)->leaf && (*root)->count == 0)
    {
        BPlusNode *old_root = *root;
        *root = old_root->children[0];
        free(old_root);
    }

    if ((*root)->leaf && (*root)->count == 0)
    {
        free(*root);
        *root = NULL;
        return 1;
    }

    update_keys(*root);
    return 1;
}

void print_leaves(BPlusNode *root)
{
    BPlusNode *leaf = root;

    if (leaf == NULL)
    {
        printf("Empty tree\n");
        return;
    }

    while (!leaf->leaf)
    {
        leaf = leaf->children[0];
    }

    while (leaf != NULL)
    {
        for (int i = 0; i < leaf->count; i++)
        {
            printf("%d ", leaf->keys[i]);
        }

        leaf = leaf->next;
    }

    printf("\n");
}

void free_tree(BPlusNode *root)
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
    BPlusNode *root = NULL;
    int values[] = {50, 20, 70, 10, 30, 60, 80, 40, 90, 100};
    int length = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < length; i++)
    {
        insert(&root, values[i]);
    }

    printf("Leaves: ");
    print_leaves(root);

    printf("Search 70: %s\n",
           search(root, 70) ? "Found" : "Not found");

    delete_value(&root, 70);
    delete_value(&root, 30);

    printf("After deletion: ");
    print_leaves(root);

    insert(&root, 25);
    insert(&root, 75);

    printf("After insertion: ");
    print_leaves(root);

    free_tree(root);

    return 0;
}
