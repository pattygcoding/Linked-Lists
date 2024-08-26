class CircularNode {
    data: number;
    next: CircularNode | null;

    constructor(data: number) {
        this.data = data;
        this.next = null;
    }
}

class CircularLinkedList {
    head: CircularNode | null;

    constructor() {
        this.head = null;
    }

    insert(data: number): void {
        const newNode = new CircularNode(data);
        if (this.head === null) {
            this.head = newNode;
            newNode.next = this.head;
        } else {
            let temp = this.head;
            while (temp.next !== this.head) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = this.head;
        }
    }

    deleteNode(key: number): void {
        if (this.head === null) return;

        let current = this.head;
        let prev: CircularNode | null = null;

        // If the node to be deleted is the head node
        if (current.data === key) {
            while (current.next !== this.head) {
                current = current.next;
            }

            if (this.head.next === this.head) {
                this.head = null;
                return;
            }

            current.next = this.head.next;
            this.head = current.next;
            return;
        }

        // Search for the node to be deleted
        do {
            prev = current;
            current = current.next;
        } while (current !== this.head && current.data !== key);

        if (current.data === key && prev !== null) {
            prev.next = current.next;
        }
    }

    display(): void {
        if (this.head === null) return;
        let current = this.head;
        do {
            process.stdout.write(`${current.data} -> `);
            current = current.next;
        } while (current !== this.head);
        console.log('(head)');
    }
}

// Example usage
const list = new CircularLinkedList();
list.insert(3);
list.insert(2);
list.insert(1);

console.log('Original List:');
list.display();

list.deleteNode(2);
console.log('After Deleting 2:');
list.display();
