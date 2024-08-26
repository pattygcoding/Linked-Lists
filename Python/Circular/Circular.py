class CircularNode:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = CircularNode(data)
        if self.head is None:
            self.head = new_node
            new_node.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def delete_node(self, key):
        if self.head is None:
            return

        current = self.head
        prev = None

        # If the node to be deleted is the head node
        if current.data == key:
            while current.next != self.head:
                current = current.next

            if self.head.next == self.head:
                self.head = None
                return

            current.next = self.head.next
            self.head = current.next
            return

        # Search for the node to be deleted
        while current.next != self.head and current.data != key:
            prev = current
            current = current.next

        if current.data == key:
            prev.next = current.next

    def display(self):
        if self.head is None:
            return
        current = self.head
        while True:
            print(current.data, end=" -> ")
            current = current.next
            if current == self.head:
                break
        print("(head)")

# Example usage
list = CircularLinkedList()
list.insert(3)
list.insert(2)
list.insert(1)

print("Original List:")
list.display()

list.delete_node(2)
print("After Deleting 2:")
list.display()
