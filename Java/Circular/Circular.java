class CircularNode {
    int data;
    CircularNode next;

    CircularNode(int data) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    CircularNode head;

    public CircularLinkedList() {
        this.head = null;
    }

    public void insert(int data) {
        CircularNode newNode = new CircularNode(data);
        if (head == null) {
            head = newNode;
            newNode.next = head;
        } else {
            CircularNode temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = head;
        }
    }

    public void deleteNode(int key) {
        if (head == null) return;

        CircularNode current = head, prev = null;

        // If the node to be deleted is the head node
        if (current.data == key) {
            while (current.next != head) {
                current = current.next;
            }

            if (head.next == head) {
                head = null;
                return;
            }

            current.next = head.next;
            head = current.next;
            return;
        }

        // Search for the node to be deleted
        do {
            prev = current;
            current = current.next;
        } while (current != head && current.data != key);

        if (current.data == key) {
            prev.next = current.next;
        }
    }

    public void display() {
        if (head == null) return;
        CircularNode current = head;
        do {
            System.out.print(current.data + " -> ");
            current = current.next;
        } while (current != head);
        System.out.println("(head)");
    }

    public static void main(String[] args) {
        CircularLinkedList list = new CircularLinkedList();
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
