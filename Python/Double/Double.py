class DoublyNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = DoublyNode(data)
        new_node.next = self.head
        if self.head is not None:
            self.head.prev = new_node
        self.head = new_node

    def delete_node(self, key):
        temp = self.head

        # If head node itself holds the key
        if temp is not None and temp.data == key:
            self.head = temp.next
            if self.head is not None:
                self.head.prev = None
            return

        # Search for the key to be deleted
        while temp is not None and temp.data != key:
            temp = temp.next

        # If key was not present in the list
        if temp is None:
            return

        if temp.next is not None:
            temp.next.prev = temp.prev

        if temp.prev is not None:
            temp.prev.next = temp.next

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

# Example usage
list = DoublyLinkedList()
list.insert(3)
list.insert(2)
list.insert(1)

print("Original List:")
list.display()

list.delete_node(2)
print("After Deleting 2:")
list.display()
