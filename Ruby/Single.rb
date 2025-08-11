class Node
  attr_accessor :data, :next

  def initialize(data)
    @data = data
    @next = nil
  end
end

class SinglyLinkedList
  def initialize
    @head = nil
  end

  def insert(data)
    new_node = Node.new(data)
    new_node.next = @head
    @head = new_node
  end

  def delete_node(key)
    temp = @head
    prev = nil

    if temp && temp.data == key
      @head = temp.next
      return
    end

    while temp && temp.data != key
      prev = temp
      temp = temp.next
    end

    return unless temp
    prev.next = temp.next
  end

  def delete_head
    @head = @head.next if @head
  end

  def delete_last
    return unless @head
    return @head = nil unless @head.next
    cur = @head
    cur = cur.next while cur.next && cur.next.next
    cur.next = nil
  end

  def display
    cur = @head
    while cur
      print "#{cur.data} -> "
      cur = cur.next
    end
    puts "null"
  end
end

list = SinglyLinkedList.new
list.insert(3)
list.insert(2)
list.insert(1)
puts "Original List:"
list.display
list.delete_node(2)
puts "After Deleting 2:"
list.display
