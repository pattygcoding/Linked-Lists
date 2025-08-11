public class SinglyLinkedList {
    static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }

    private Node head;

    public void insert(int data) {
        Node n = new Node(data);
        n.next = head;
        head = n;
    }

    public void deleteNode(int key) {
        Node temp = head, prev = null;

        if (temp != null && temp.data == key) {
            head = temp.next;
            return;
        }

        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) return;

        prev.next = temp.next;
    }

    public void deleteHead() {
        if (head != null) head = head.next;
    }

    public void deleteLast() {
        if (head == null) return;
        if (head.next == null) { head = null; return; }
        Node cur = head;
        while (cur.next.next != null) cur = cur.next;
        cur.next = null;
    }

    public void display() {
        Node cur = head;
        while (cur != null) {
            System.out.print(cur.data + " -> ");
            cur = cur.next;
        }
        System.out.println("null");
    }

    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
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
