class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyCircularLinkedList {
    constructor() {
        this.head = null;
    }

    insert(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            newNode.next = newNode;
            newNode.prev = newNode;
        } else {
            const last = this.head.prev;
            last.next = newNode;
            newNode.next = this.head;
            newNode.prev = last;
            this.head.prev = newNode;
        }
    }

    deleteNode(key) {
        if (this.head === null) return;

        let current = this.head;

        // If the head node holds the key
        if (current.data === key) {
            if (current.next === this.head) {
                this.head = null;
                return;
            }

            const last = this.head.prev;
            last.next = current.next;
            current.next.prev = last;
            this.head = current.next;
            return;
        }

        // Search for the node to be deleted
        while (current.next !== this.head && current.data !== key) {
            current = current.next;
        }

        if (current.data === key) {
            current.prev.next = current.next;
            current.next.prev = current.prev;
        }
    }

    display() {
        if (this.head === null) return;
        let current = this.head;
        do {
            process.stdout.write(current.data + ' <-> ');
            current = current.next;
        } while (current !== this.head);
        console.log('(head)');
    }
}

// Example usage
const list = new DoublyCircularLinkedList();
list.insert(3);
list.insert(2);
list.insert(1);

console.log('Original List:');
list.display();

list.deleteNode(2);
console.log('After Deleting 2:');
list.display();
