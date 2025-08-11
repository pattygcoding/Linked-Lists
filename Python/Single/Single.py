class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_node(self, key):
        temp = self.head
        prev = None

        if temp and temp.data == key:
            self.head = temp.next
            return

        while temp and temp.data != key:
            prev = temp
            temp = temp.next

        if temp is None:
            return

        prev.next = temp.next

    def delete_head(self):
        if self.head:
            self.head = self.head.next

    def delete_last(self):
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            return
        cur = self.head
        while cur.next.next is not None:
            cur = cur.next
        cur.next = None

    def display(self):
        cur = self.head
        while cur:
            print(f"{cur.data} -> ", end="")
            cur = cur.next
        print("null")


if __name__ == "__main__":
    lst = SinglyLinkedList()
    lst.insert(3); lst.insert(2); lst.insert(1)
    print("Original List:")
    lst.display()
    lst.delete_node(2)
    print("After Deleting 2:")
    lst.display()
