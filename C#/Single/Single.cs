using System;

public class Node
{
    public int Data;
    public Node Next;

    public Node(int data)
    {
        Data = data;
        Next = null;
    }
}

public class SingleLinkedList
{
    public Node Head;

    public SingleLinkedList()
    {
        Head = null;
    }

    public void Insert(int data)
    {
        Node newNode = new Node(data);
        newNode.Next = Head;
        Head = newNode;
    }

    public void DeleteNode(int key)
    {
        Node temp = Head;
        Node prev = null;

        // If head node itself holds the key
        if (temp != null && temp.Data == key)
        {
            Head = temp.Next;
            return;
        }

        // Search for the key to be deleted
        while (temp != null && temp.Data != key)
        {
            prev = temp;
            temp = temp.Next;
        }

        // If key was not present in the list
        if (temp == null) return;

        prev.Next = temp.Next;
    }

    public void Display()
    {
        Node current = Head;
        while (current != null)
        {
            Console.Write(current.Data + " -> ");
            current = current.Next;
        }
        Console.WriteLine("null");
    }

    public void DeleteHead()
    {
        if (Head != null)
            Head = Head.Next;
    }
}

class Program
{
    static void Main()
    {
        SingleLinkedList list = new SingleLinkedList();
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
