#include <iostream>

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
public:
    Node* head;

    SingleLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        // If the head node holds the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next; // Change head
            delete temp; // Free old head
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in the list
        if (temp == nullptr) return;

        // Unlink the node from the linked list
        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }
};

int main() {
    SingleLinkedList list;
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
