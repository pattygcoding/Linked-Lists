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

public class DoublyCircularLinkedList
{
    public Node Head;

    public DoublyCircularLinkedList()
    {
        Head = null;
    }

    public void Insert(int data)
    {
        Node newNode = new Node(data);
        if (Head == null)
        {
            Head = newNode;
            newNode.Next = Head;
            newNode.Prev = Head;
        }
        else
        {
            Node last = Head.Prev;
            last.Next = newNode;
            newNode.Next = Head;
            newNode.Prev = last;
            Head.Prev = newNode;
        }
    }

    public void DeleteNode(int key)
    {
        if (Head == null) return;

        Node current = Head;

        // If the head node holds the key
        if (current.Data == key)
        {
            if (current.Next == Head)
            {
                Head = null;
                return;
            }

            Node last = Head.Prev;
            last.Next = current.Next;
            current.Next.Prev = last;
            Head = current.Next;
            return;
        }

        // Search for the node to be deleted
        while (current.Next != Head && current.Data != key)
        {
            current = current.Next;
        }

        if (current.Data == key)
        {
            current.Prev.Next = current.Next;
            current.Next.Prev = current.Prev;
        }
    }

    public void Display()
    {
        if (Head == null) return;
        Node current = Head;
        do
        {
            Console.Write(current.Data + " <-> ");
            current = current.Next;
        } while (current != Head);
        Console.WriteLine("(head)");
    }
}

class Program
{
    static void Main()
    {
        DoublyCircularLinkedList list = new DoublyCircularLinkedList();
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
