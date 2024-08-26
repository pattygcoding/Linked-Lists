#include <iostream>

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int key) {
        if (head == nullptr) return;

        Node *current = head, *prev = nullptr;

        // If the node to be deleted is the head node
        if (current->data == key) {
            while (current->next != head) {
                current = current->next;
            }

            if (head->next == head) { // Single node case
                delete head;
                head = nullptr;
                return;
            }

            current->next = head->next;
            delete head;
            head = current->next;
            return;
        }

        // Search for the node to be deleted
        do {
            prev = current;
            current = current->next;
        } while (current != head && current->data != key);

        // If node with key not found
        if (current == head) return;

        prev->next = current->next;
        delete current;
    }

    void display() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        std::cout << "(head)" << std::endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insert(3);
    list.insert(2);
    list.insert(1);

    std::cout << "Original List: ";
    list.display();

    list.deleteNode(2);
    std::cout << "After Deleting 2: ";
    list.display();

    return 0;
}
