class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_node(self, key):
        temp = self.head
        prev = None

        # If head node itself holds the key
        if temp is not None and temp.data == key:
            self.head = temp.next
            return

        # Search for the key to be deleted
        while temp is not None and temp.data != key:
            prev = temp
            temp = temp.next

        # If key was not present in the list
        if temp is None:
            return

        prev.next = temp.next

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Example usage
list = SingleLinkedList()
list.insert(3)
list.insert(2)
list.insert(1)

print("Original List:")
list.display()

list.delete_node(2)
print("After Deleting 2:")
list.display()
