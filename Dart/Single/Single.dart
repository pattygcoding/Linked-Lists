class Node {
  int data;
  Node? next;
  Node(this.data);
}

class SinglyLinkedList {
  Node? head;

  void insert(int data) {
    var newNode = Node(data);
    newNode.next = head;
    head = newNode;
  }

  void deleteNode(int key) {
    Node? temp = head, prev;

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

  void deleteHead() {
    if (head != null) head = head!.next;
  }

  void deleteLast() {
    if (head == null) return;
    if (head!.next == null) { head = null; return; }
    var cur = head;
    while (cur!.next!.next != null) {
      cur = cur.next;
    }
    cur.next = null;
  }

  void display() {
    var cur = head;
    while (cur != null) {
      stdout.write("${cur.data} -> ");
      cur = cur.next;
    }
    print("null");
  }
}

void main() {
  var list = SinglyLinkedList();
  list.insert(3);
  list.insert(2);
  list.insert(1);
  print("Original List:");
  list.display();
  list.deleteNode(2);
  print("After Deleting 2:");
  list.display();
}
