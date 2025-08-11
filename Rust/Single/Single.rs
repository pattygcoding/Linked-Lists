use std::fmt;

struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

struct SinglyLinkedList {
    head: Option<Box<Node>>,
}

impl SinglyLinkedList {
    fn new() -> Self {
        Self { head: None }
    }

    fn insert(&mut self, data: i32) {
        let new_node = Box::new(Node { data, next: self.head.take() });
        self.head = Some(new_node);
    }

    fn delete_node(&mut self, key: i32) {
        let mut cur = &mut self.head;

        while let Some(ref mut node) = cur {
            if node.data == key {
                *cur = node.next.take();
                return;
            }
            cur = &mut node.next;
        }
    }

    fn delete_head(&mut self) {
        if let Some(node) = self.head.take() {
            self.head = node.next;
        }
    }

    fn delete_last(&mut self) {
        let mut cur = &mut self.head;

        if cur.is_none() {
            return;
        }

        if cur.as_ref().unwrap().next.is_none() {
            self.head = None;
            return;
        }

        while let Some(ref mut node) = cur {
            if node.next.as_ref().map_or(false, |next| next.next.is_none()) {
                node.next = None;
                return;
            }
            cur = &mut node.next;
        }
    }

    fn display(&self) {
        let mut cur = &self.head;
        while let Some(node) = cur {
            print!("{} -> ", node.data);
            cur = &node.next;
        }
        println!("null");
    }
}

fn main() {
    let mut list = SinglyLinkedList::new();
    list.insert(3);
    list.insert(2);
    list.insert(1);

    println!("Original List:");
    list.display();

    list.delete_node(2);
    println!("After Deleting 2:");
    list.display();
}
