#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteNode(int key) {
        if (head == nullptr) return;

        Node* current = head;

        // If head node itself holds the key
        if (current->data == key) {
            if (head->next == head) { // Only one node
                delete head;
                head = nullptr;
                return;
            }

            Node* last = head->prev;
            last->next = head->next;
            head->next->prev = last;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node to be deleted
        do {
            current = current->next;
        } while (current != head && current->data != key);

        // If node with key not found
        if (current == head) return;

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    void display() {
        if (head == nullptr) return;
        Node* current = head;
        do {
            std::cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        std::cout << "(head)" << std::endl;
    }
};

int main() {
    DoublyCircularLinkedList list;
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
