class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
    }

    insert(data) {
        const newNode = new Node(data);
        newNode.next = this.head;
        if (this.head !== null) {
            this.head.prev = newNode;
        }
        this.head = newNode;
    }

    deleteNode(key) {
        let temp = this.head;

        // If head node itself holds the key
        if (temp !== null && temp.data === key) {
            this.head = temp.next;
            if (this.head !== null) {
                this.head.prev = null;
            }
            return;
        }

        // Search for the key to be deleted
        while (temp !== null && temp.data !== key) {
            temp = temp.next;
        }

        // If key was not present in the list
        if (temp === null) return;

        if (temp.next !== null) {
            temp.next.prev = temp.prev;
        }

        if (temp.prev !== null) {
            temp.prev.next = temp.next;
        }
    }

    display() {
        let current = this.head;
        while (current !== null) {
            process.stdout.write(current.data + ' <-> ');
            current = current.next;
        }
        console.log('null');
    }
}

// Example usage
const list = new DoublyLinkedList();
list.insert(3);
list.insert(2);
list.insert(1);

console.log('Original List:');
list.display();

list.deleteNode(2);
console.log('After Deleting 2:');
list.display();
