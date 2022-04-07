package main

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
	len  int
}

func NewList() *LinkedList {
	return &LinkedList{}
}

func (l *LinkedList) Insert(val int) {
	newNode := Node{}
	newNode.value = val

	if l.len == 0 {
		l.head = &newNode
		l.len++
		return
	}

	ptr := l.head

	for i := 0; i < l.len; i++ {
		if ptr.next == nil {
			ptr.next = &newNode
			l.len++
			return
		}
		ptr = ptr.next
	}
}

func (l *LinkedList) InsertAt(pos, val int) {
	newNode := Node{}
	newNode.value = val

	if pos < 0 || pos > l.len {
		return
	} else if pos == 0 {
		if l.len != 0 {
			headNode := l.GetAtPos(0)
			newNode.next = headNode
		}

		l.head = &newNode

		l.len++
		return
	}

	n := l.GetAtPos(pos)
	newNode.next = n
	prevNode := l.GetAtPos(pos - 1)
	prevNode.next = &newNode
	l.len++
}

func (l *LinkedList) GetAtPos(pos int) *Node {
	ptr := l.head

	if pos <= 0 {
		return ptr
	} else if pos >= l.len {
		return nil
	}

	for i := 0; i < pos; i++ {
		ptr = ptr.next
	}
	return ptr
}
