class DoublyCircularNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyCircularLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = DoublyCircularNode(data)
        if self.head is None:
            self.head = new_node
            new_node.next = new_node
            new_node.prev = new_node
        else:
            last = self.head.prev
            last.next = new_node
            new_node.next = self.head
            new_node.prev = last
            self.head.prev = new_node

    def delete_node(self, key):
        if self.head is None:
            return

        current = self.head

        # If the head node holds the key
        if current.data == key:
            if current.next == self.head:
                self.head = None
                return

            last = self.head.prev
            last.next = current.next
            current.next.prev = last
            self.head = current.next
            return

        # Search for the node to be deleted
        while current.next != self.head and current.data != key:
            current = current.next

        if current.data == key:
            current.prev.next = current.next
            current.next.prev = current.prev

    def display(self):
        if self.head is None:
            return
        current = self.head
        while True:
            print(current.data, end=" <-> ")
            current = current.next
            if current == self.head:
                break
        print("(head)")

# Example usage
list = DoublyCircularLinkedList()
list.insert(3)
list.insert(2)
list.insert(1)

print("Original List:")
list.display()

list.delete_node(2)
print("After Deleting 2:")
list.display()
