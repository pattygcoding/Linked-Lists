#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        struct Node* last = (*head_ref)->prev;
        last->next = new_node;
        new_node->next = *head_ref;
        new_node->prev = last;
        (*head_ref)->prev = new_node;
    }
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node* current = *head_ref;

    if (current->data == key) {
        if (current->next == *head_ref) {
            free(current);
            *head_ref = NULL;
            return;
        }

        struct Node* last = (*head_ref)->prev;
        last->next = current->next;
        current->next->prev = last;
        *head_ref = current->next;
        free(current);
        return;
    }

    while (current->next != *head_ref && current->data != key) {
        current = current->next;
    }

    if (current->data != key) return;

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
}

void display(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original List: ");
    display(head);

    deleteNode(&head, 2);
    printf("After Deleting 2: ");
    display(head);

    return 0;
}
