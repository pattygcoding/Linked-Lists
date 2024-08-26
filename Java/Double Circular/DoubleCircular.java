class DoublyCircularNode {
    int data;
    DoublyCircularNode next;
    DoublyCircularNode prev;

    DoublyCircularNode(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCircularLinkedList {
    DoublyCircularNode head;

    public DoublyCircularLinkedList() {
        this.head = null;
    }

    public void insert(int data) {
        DoublyCircularNode newNode = new DoublyCircularNode(data);
        if (head == null) {
            head = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            DoublyCircularNode last = head.prev;
            last.next = newNode;
            newNode.next = head;
            newNode.prev = last;
            head.prev = newNode;
        }
    }

    public void deleteNode(int key) {
        if (head == null) return;

        DoublyCircularNode current = head;

        // If the head node holds the key
        if (current.data == key) {
            if (current.next == head) {
                head = null;
                return;
            }

            DoublyCircularNode last = head.prev;
            last.next = current.next;
            current.next.prev = last;
            head = current.next;
            return;
        }

        // Search for the node to be deleted
        while (current.next != head && current.data != key) {
            current = current.next;
        }

        if (current.data == key) {
            current.prev.next = current.next;
            current.next.prev = current.prev;
        }
    }

    public void display() {
        if (head == null) return;
        DoublyCircularNode current = head;
        do {
            System.out.print(current.data + " <-> ");
            current = current.next;
        } while (current != head);
        System.out.println("(head)");
    }

    public static void main(String[] args) {
        DoublyCircularLinkedList list = new DoublyCircularLinkedList();
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
