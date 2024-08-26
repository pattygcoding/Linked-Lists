class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class SingleLinkedList {
    constructor() {
        this.head = null;
    }

    insert(data) {
        const newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    deleteNode(key) {
        let temp = this.head;
        let prev = null;

        // If head node itself holds the key
        if (temp !== null && temp.data === key) {
            this.head = temp.next;
            return;
        }

        // Search for the key to be deleted
        while (temp !== null && temp.data !== key) {
            prev = temp;
            temp = temp.next;
        }

        // If key was not present in the list
        if (temp === null) return;

        prev.next = temp.next;
    }

    display() {
        let current = this.head;
        while (current !== null) {
            process.stdout.write(current.data + ' -> ');
            current = current.next;
        }
        console.log('null');
    }
}

// Example usage
const list = new SingleLinkedList();
list.insert(3);
list.insert(2);
list.insert(1);

console.log('Original List:');
list.display();

list.deleteNode(2);
console.log('After Deleting 2:');
list.display();
