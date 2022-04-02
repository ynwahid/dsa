# Circular Queue implementation in Python
# Source: https://www.programiz.com/dsa/circular-queue
class MyCircularQueue:

    
    def __init__(self, k: int) -> None:
        self.k = k
        self.queue = [None] * self.k
        self.head = self.tail = -1

    # Insert an element into the circular queue
    def enqueue(self, data: int) -> None:
        if (self.tail + 1) % self.k == self.head:
            print('The circular queue is full!\n')
        
        elif self.head == -1:
            self.head = 0
            self.tail = 0
            self.queue[self.tail] = data
        
        else:
            self.tail = (self.tail + 1) % self.k
            self.queue[self.tail] = data

    # Delete an element from the circular queue
    def deQueue(self) -> int:
        if self.head == -1:
            print('The circular queue is empty!\n')
        
        elif self.head == self.tail:
            self.head = -1
            self.tail = -1
        else:
            self.head = (self.head + 1) % self.k
    
    def printCQueue(self) -> None:
        if self.head == -1:
            print('No element in the circular queue.')
        
        elif self.tail >= self.head:
            for i in range(self.head, self.tail + 1):
                print(self.queue[i], end=' ')
            print()
        
        else:
            for i in range(self.head, self.k):
                print(self.queue[i], end=' ')
            for i in range(0, self.tail + 1):
                print(self.queue[i], end=' ')
            print()
        
if __name__ == '__main__':
    circularQueue = MyCircularQueue(5)

    # Enqueue
    circularQueue.enqueue(1)
    circularQueue.enqueue(2)
    circularQueue.enqueue(3)
    circularQueue.enqueue(4)
    circularQueue.enqueue(5)

    print("Initial queue:")

    circularQueue.printCQueue()

    print('After removing an element from the queue:')
    circularQueue.deQueue()
    circularQueue.printCQueue()