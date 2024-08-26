#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head_ref;
    }
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) return;

    struct Node *current = *head_ref, *prev = NULL;

    if (current->data == key) {
        while (current->next != *head_ref) {
            current = current->next;
        }

        if (*head_ref == (*head_ref)->next) {
            free(*head_ref);
            *head_ref = NULL;
            return;
        }

        current->next = (*head_ref)->next;
        free(*head_ref);
        *head_ref = current->next;
        return;
    }

    while (current->next != *head_ref && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current->data != key) return;

    prev->next = current->next;
    free(current);
}

void display(struct Node* head) {
    if (head == NULL) return;
    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
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
