#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the list
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
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