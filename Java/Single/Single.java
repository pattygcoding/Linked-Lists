class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class SingleLinkedList {
    Node head;

    public SingleLinkedList() {
        this.head = null;
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    public void deleteNode(int key) {
        Node temp = head;
        Node prev = null;

        // If head node itself holds the key
        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }

        // Search for the key to be deleted
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }

        // If key was not present in the list
        if (temp == null) return;

        prev.next = temp.next;
    }

    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        SingleLinkedList list = new SingleLinkedList();
        list.insert(3);
        list.insert(2);
        list.insert(1);

        System.out.println("Original List:");
        list.display();

        list.deleteNode(2);
        System.out.println("After Deleting 2:");
        list.display();
    }
}
