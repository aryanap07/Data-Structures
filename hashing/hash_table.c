#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node **buckets;
    size_t capacity;
    size_t size;
} HashTable;

size_t hash(int key, size_t capacity) {
    return (size_t)((uint32_t)key % capacity);
}

Node *create_node(int key, int value) {
    Node *node = malloc(sizeof(*node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->key = key;
    node->value = value;
    node->next = NULL;

    return node;
}

HashTable *create_table(size_t capacity) {
    if (capacity == 0) {
        fprintf(stderr, "Hash table capacity must be greater than zero\n");
        exit(EXIT_FAILURE);
    }

    HashTable *table = malloc(sizeof(*table));

    if (table == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    table->buckets = calloc(capacity, sizeof(*table->buckets));

    if (table->buckets == NULL) {
        free(table);
        perror("calloc");
        exit(EXIT_FAILURE);
    }

    table->capacity = capacity;
    table->size = 0;

    return table;
}

void destroy_table(HashTable **table) {
    if (table == NULL || *table == NULL)
        return;

    for (size_t i = 0; i < (*table)->capacity; i++) {
        Node *current = (*table)->buckets[i];

        while (current != NULL) {
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    free((*table)->buckets);
    free(*table);
    *table = NULL;
}

bool insert(HashTable *table, int key, int value) {
    size_t index = hash(key, table->capacity);

    for (Node *current = table->buckets[index];
         current != NULL;
         current = current->next) {
        if (current->key == key) {
            current->value = value;
            return false;
        }
    }

    Node *node = create_node(key, value);
    node->next = table->buckets[index];
    table->buckets[index] = node;
    table->size++;

    return true;
}

bool search(const HashTable *table, int key, int *value) {
    size_t index = hash(key, table->capacity);

    for (Node *current = table->buckets[index];
         current != NULL;
         current = current->next) {
        if (current->key == key) {
            if (value != NULL)
                *value = current->value;

            return true;
        }
    }

    return false;
}

bool contains(const HashTable *table, int key) {
    return search(table, key, NULL);
}

bool delete(HashTable *table, int key) {
    size_t index = hash(key, table->capacity);
    Node **link = &table->buckets[index];

    while (*link != NULL) {
        if ((*link)->key == key) {
            Node *node = *link;
            *link = node->next;

            free(node);
            table->size--;

            return true;
        }

        link = &(*link)->next;
    }

    return false;
}

size_t size(const HashTable *table) {
    return table->size;
}

bool is_empty(const HashTable *table) {
    return table->size == 0;
}

void display(const HashTable *table) {
    for (size_t i = 0; i < table->capacity; i++) {
        printf("[%zu] -> ", i);

        for (Node *current = table->buckets[i];
             current != NULL;
             current = current->next) {
            printf("(%d, %d)", current->key, current->value);

            if (current->next != NULL)
                printf(" -> ");
        }

        printf("\n");
    }
}

int main(void) {
    HashTable *table = create_table(10);

    insert(table, 10, 100);
    insert(table, 20, 200);
    insert(table, -15, 150);
    insert(table, 25, 250);
    insert(table, 35, 350);

    printf("Hash Table:\n");
    display(table);

    int value;

    if (search(table, -15, &value))
        printf("Key -15: %d\n", value);

    insert(table, 20, 500);

    if (search(table, 20, &value))
        printf("Updated key 20: %d\n", value);

    delete(table, 25);

    printf("After deletion:\n");
    display(table);

    printf("Size: %zu\n", size(table));
    printf("Contains 35: %s\n",
           contains(table, 35) ? "Yes" : "No");
    printf("Is empty: %s\n",
           is_empty(table) ? "Yes" : "No");

    destroy_table(&table);

    return EXIT_SUCCESS;
}
