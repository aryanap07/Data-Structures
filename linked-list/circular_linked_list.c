#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int data) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void insert_at_beginning(Node **tail, int data) {
    Node *node = create_node(data);

    if (*tail == NULL) {
        node->next = node;
        *tail = node;
        return;
    }

    node->next = (*tail)->next;
    (*tail)->next = node;
}

void insert_at_end(Node **tail, int data) {
    Node *node = create_node(data);

    if (*tail == NULL) {
        node->next = node;
        *tail = node;
        return;
    }

    node->next = (*tail)->next;
    (*tail)->next = node;
    *tail = node;
}

void insert_at_position(Node **tail, int data, size_t position) {
    if (*tail == NULL || position == 0) {
        insert_at_beginning(tail, data);
        return;
    }

    Node *current = (*tail)->next;

    for (size_t i = 0; i < position - 1 && current != *tail; i++)
        current = current->next;

    if (current == *tail && position > 1)
        return;

    Node *node = create_node(data);
    node->next = current->next;
    current->next = node;

    if (current == *tail)
        *tail = node;
}

void delete_from_beginning(Node **tail) {
    if (*tail == NULL)
        return;

    Node *head = (*tail)->next;

    if (head == *tail) {
        free(*tail);
        *tail = NULL;
        return;
    }

    (*tail)->next = head->next;
    free(head);
}

void delete_from_end(Node **tail) {
    if (*tail == NULL)
        return;

    Node *head = (*tail)->next;

    if (head == *tail) {
        free(*tail);
        *tail = NULL;
        return;
    }

    Node *current = head;

    while (current->next != *tail)
        current = current->next;

    current->next = (*tail)->next;
    free(*tail);
    *tail = current;
}

void delete_at_position(Node **tail, size_t position) {
    if (*tail == NULL)
        return;

    if (position == 0) {
        delete_from_beginning(tail);
        return;
    }

    Node *current = (*tail)->next;

    for (size_t i = 0; i < position - 1 && current != *tail; i++)
        current = current->next;

    if (current == *tail)
        return;

    Node *temp = current->next;

    if (temp == *tail)
        *tail = current;

    current->next = temp->next;
    free(temp);
}

Node *search(Node *tail, int data) {
    if (tail == NULL)
        return NULL;

    Node *current = tail->next;

    do {
        if (current->data == data)
            return current;

        current = current->next;
    } while (current != tail->next);

    return NULL;
}

size_t length(Node *tail) {
    if (tail == NULL)
        return 0;

    size_t count = 0;
    Node *current = tail->next;

    do {
        count++;
        current = current->next;
    } while (current != tail->next);

    return count;
}

void reverse(Node **tail) {
    if (*tail == NULL || (*tail)->next == *tail)
        return;

    Node *head = (*tail)->next;
    Node *previous = *tail;
    Node *current = head;

    do {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    } while (current != head);

    *tail = head;
}

void display(Node *tail) {
    if (tail == NULL) {
        printf("NULL\n");
        return;
    }

    Node *current = tail->next;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != tail->next);

    printf("(head)\n");
}

void destroy(Node **tail) {
    if (*tail == NULL)
        return;

    Node *head = (*tail)->next;
    (*tail)->next = NULL;

    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    *tail = NULL;
}

int main(void) {
    Node *tail = NULL;

    insert_at_end(&tail, 10);
    insert_at_end(&tail, 20);
    insert_at_end(&tail, 30);

    insert_at_beginning(&tail, 5);
    insert_at_position(&tail, 15, 2);

    display(tail);

    delete_from_beginning(&tail);
    delete_from_end(&tail);
    delete_at_position(&tail, 1);

    display(tail);

    printf("Length: %zu\n", length(tail));

    if (search(tail, 20) != NULL)
        printf("20 found\n");

    reverse(&tail);
    display(tail);

    destroy(&tail);

    return 0;
}
