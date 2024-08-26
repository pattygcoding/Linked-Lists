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

public class CircularLinkedList
{
    public Node Head;

    public CircularLinkedList()
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
        }
        else
        {
            Node temp = Head;
            while (temp.Next != Head)
            {
                temp = temp.Next;
            }
            temp.Next = newNode;
            newNode.Next = Head;
        }
    }

    public void DeleteNode(int key)
    {
        if (Head == null) return;

        Node current = Head, prev = null;

        // If the node to be deleted is the head node
        if (current.Data == key)
        {
            while (current.Next != Head)
            {
                current = current.Next;
            }

            if (Head.Next == Head)
            {
                Head = null;
                return;
            }

            current.Next = Head.Next;
            Head = current.Next;
            return;
        }

        // Search for the node to be deleted
        do
        {
            prev = current;
            current = current.Next;
        } while (current != Head && current.Data != key);

        if (current.Data == key)
        {
            prev.Next = current.Next;
        }
    }

    public void Display()
    {
        if (Head == null) return;
        Node current = Head;
        do
        {
            Console.Write(current.Data + " -> ");
            current = current.Next;
        } while (current != Head);
        Console.WriteLine("(head)");
    }
}

class Program
{
    static void Main()
    {
        CircularLinkedList list = new CircularLinkedList();
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
