package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type SinglyLinkedList struct {
	head *Node
}

func (l *SinglyLinkedList) Insert(data int) {
	newNode := &Node{data: data, next: l.head}
	l.head = newNode
}

func (l *SinglyLinkedList) DeleteNode(key int) {
	temp := l.head
	var prev *Node

	if temp != nil && temp.data == key {
		l.head = temp.next
		return
	}

	for temp != nil && temp.data != key {
		prev = temp
		temp = temp.next
	}

	if temp == nil {
		return
	}

	prev.next = temp.next
}

func (l *SinglyLinkedList) DeleteHead() {
	if l.head != nil {
		l.head = l.head.next
	}
}

func (l *SinglyLinkedList) DeleteLast() {
	if l.head == nil {
		return
	}
	if l.head.next == nil {
		l.head = nil
		return
	}
	cur := l.head
	for cur.next.next != nil {
		cur = cur.next
	}
	cur.next = nil
}

func (l *SinglyLinkedList) Display() {
	cur := l.head
	for cur != nil {
		fmt.Printf("%d -> ", cur.data)
		cur = cur.next
	}
	fmt.Println("null")
}

func main() {
	list := SinglyLinkedList{}
	list.Insert(3)
	list.Insert(2)
	list.Insert(1)
	fmt.Println("Original List:")
	list.Display()
	list.DeleteNode(2)
	fmt.Println("After Deleting 2:")
	list.Display()
}
