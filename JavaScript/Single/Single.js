class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class SinglyLinkedList {
  constructor() {
    this.head = null;
  }

  insert(data) {
    const n = new Node(data);
    n.next = this.head;
    this.head = n;
  }

  deleteNode(key) {
    let temp = this.head, prev = null;

    if (temp && temp.data === key) {
      this.head = temp.next;
      return;
    }

    while (temp && temp.data !== key) {
      prev = temp;
      temp = temp.next;
    }
    if (!temp) return;

    prev.next = temp.next;
  }

  deleteHead() {
    if (this.head) this.head = this.head.next;
  }

  deleteLast() {
    if (!this.head) return;
    if (!this.head.next) { this.head = null; return; }
    let cur = this.head;
    while (cur.next && cur.next.next) cur = cur.next;
    cur.next = null;
  }

  display() {
    let cur = this.head, parts = [];
    while (cur) { parts.push(cur.data); cur = cur.next; }
    console.log(parts.join(" -> ") + " -> null");
  }
}

// demo
const list = new SinglyLinkedList();
list.insert(3); list.insert(2); list.insert(1);
console.log("Original List:");
list.display();
list.deleteNode(2);
console.log("After Deleting 2:");
list.display();
