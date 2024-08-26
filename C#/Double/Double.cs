using System;

public class Node
{
    public int Data;
    public Node Next;
    public Node Prev;

    public Node(int data)
    {
        Data = data;
        Next = null;
        Prev = null;
    }
}

public class DoublyLinkedList
{
    public Node Head;

    public DoublyLinkedList()
    {
        Head = null;
    }

    public void Insert(int data)
    {
        Node newNode = new Node(data);
        newNode.Next = Head;
        if (Head != null)
        {
            Head.Prev = newNode;
        }
        Head = newNode;
    }

    public void DeleteNode(int key)
    {
        Node temp = Head;

        // If head node itself holds the key
        if (temp != null && temp.Data == key)
        {
            Head = temp.Next;
            if (Head != null)
            {
                Head.Prev = null;
            }
            return;
        }

        // Search for the key to be deleted
        while (temp != null && temp.Data != key)
        {
            temp = temp.Next;
        }

        // If key was not present in the list
        if (temp == null) return;

        if (temp.Next != null)
        {
            temp.Next.Prev = temp.Prev;
        }

        if (temp.Prev != null)
        {
            temp.Prev.Next = temp.Next;
        }
    }

    public void Display()
    {
        Node current = Head;
        while (current != null)
        {
            Console.Write(current.Data + " <-> ");
            current = current.Next;
        }
        Console.WriteLine("null");
    }
}

class Program
{
    static void Main()
    {
        DoublyLinkedList list = new DoublyLinkedList();
        list.Insert(3);
        list.Insert(2);
        list.Insert(1);

        Console.WriteLine("Original List:");
        list.Display();

        list.DeleteNode(2);
        Console.WriteLine("After Deleting 2:");
        list.Display();
    }
}
