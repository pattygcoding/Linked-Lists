class Node {
    data: number;
    next: Node | null;

    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
}

class SingleLinkedList {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    insert(data: number): void {
        const newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    deleteNode(key: number): void {
        let temp = this.head;
        let prev: Node | null = null;

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

        if (prev !== null) {
            prev.next = temp.next;
        }
    }

    display(): void {
        let current = this.head;
        while (current !== null) {
            process.stdout.write(`${current.data} -> `);
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
