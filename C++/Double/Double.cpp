#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;

        // If head node itself holds the key
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Search for the key to be deleted
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        // If key was not present in the list
        if (temp == nullptr) return;

        // Unlink the node from the linked list
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        delete temp;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }
};

int main() {
    DoublyLinkedList list;
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
