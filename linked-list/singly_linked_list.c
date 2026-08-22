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

void insert_at_beginning(Node **head, int data) {
    Node *node = create_node(data);
    node->next = *head;
    *head = node;
}

void insert_at_end(Node **head, int data) {
    Node *node = create_node(data);

    if (*head == NULL) {
        *head = node;
        return;
    }

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = node;
}

void insert_at_position(Node **head, int data, size_t position) {
    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }

    Node *current = *head;

    for (size_t i = 0; current != NULL && i < position - 1; i++)
        current = current->next;

    if (current == NULL)
        return;

    Node *node = create_node(data);
    node->next = current->next;
    current->next = node;
}

void delete_from_beginning(Node **head) {
    if (*head == NULL)
        return;

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_from_end(Node **head) {
    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *current = *head;

    while (current->next->next != NULL)
        current = current->next;

    free(current->next);
    current->next = NULL;
}

void delete_at_position(Node **head, size_t position) {
    if (*head == NULL)
        return;

    if (position == 0) {
        delete_from_beginning(head);
        return;
    }

    Node *current = *head;

    for (size_t i = 0; current->next != NULL && i < position - 1; i++)
        current = current->next;

    if (current->next == NULL)
        return;

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

Node *search(Node *head, int data) {
    for (Node *current = head; current != NULL; current = current->next) {
        if (current->data == data)
            return current;
    }

    return NULL;
}

size_t length(Node *head) {
    size_t count = 0;

    for (Node *current = head; current != NULL; current = current->next)
        count++;

    return count;
}

void reverse(Node **head) {
    Node *previous = NULL;
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *head = previous;
}

void display(Node *head) {
    for (Node *current = head; current != NULL; current = current->next)
        printf("%d -> ", current->data);

    printf("NULL\n");
}

void destroy(Node **head) {
    while (*head != NULL) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main(void) {
    Node *head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);

    insert_at_beginning(&head, 5);
    insert_at_position(&head, 15, 2);

    display(head);

    delete_from_beginning(&head);
    delete_from_end(&head);
    delete_at_position(&head, 1);

    display(head);

    printf("Length: %zu\n", length(head));

    if (search(head, 20) != NULL)
        printf("20 found\n");

    reverse(&head);
    display(head);

    destroy(&head);

    return 0;
}
