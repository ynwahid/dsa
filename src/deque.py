# Deque implementation in Python
# Source: https://www.programiz.com/dsa/deque


class Deque():


    def __init__(self) -> None:
        self.items = []

    def isEmpty(self) -> bool:
        return self.items == []

    def addFront(self, data: int) -> None:
        self.items.insert(0, data)

    def addRear(self, data: int) -> None:
        self.items.append(data)

    def removeFront(self) -> list:
        return self.items.pop(0)
        
    def removeRear(self) -> list:
        return self.items.pop()
    
    def getSize(self) -> int:
        return len(self.items)


if __name__ == '__main__':
    deque = Deque();
    print(deque.isEmpty())

    deque.addRear(8)
    deque.addRear(5)
    
    deque.addFront(7)
    deque.addFront(10)
    print(deque.items)

    print(deque.getSize())
    print(deque.isEmpty())

    deque.addRear(11)
    print(deque.items)

    print(deque.removeRear())
    print(deque.removeFront())
    print(deque.items)

    deque.addFront(55)
    deque.addRear(45)
    print(deque.items)
