# Linked list implementation in Python
# Source: https://www.programiz.com/dsa/linked-list,
# https://realpython.com/linked-lists-python/


class Node:

    # Creating a node
    def __init__(self, data) -> None:
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return self.data


class LinkedList:

    # Creating linked list
    def __init__(self) -> None:
        self.head = None
    
    def __repr__(self) -> str:
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        nodes.append("None")
        return ' -> '.join(map(str, nodes))


if __name__ == '__main__':
    # Init linked list head
    linkedList = LinkedList()
    first = Node(1)
    linkedList.head = first
    
    # Add more nodes
    second = Node(2)
    third = Node(3)
    fourth = Node(4)

    # Add pointer to other nodes
    first.next = second
    second.next = third
    third.next = fourth

    # Display
    print(linkedList)