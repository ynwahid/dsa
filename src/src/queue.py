# Queue implementation in Python
# Source: https://www.programiz.com/dsa/queue
from typing import Union


class Queue:


    def __init__(self) -> None:
        self.queue = []
        self.item = None

    # Get size
    def getSize(self):
        return len(self.queue)

    # Add an element
    def enqueu(self, item: Union[str, int]) -> None:
        self.item = item
        self.queue.append(self.item)
        print(f'Enqueue item: {self.item}')

    # Remove an element:
    def dequeue(self) -> None:
        if self.getSize() == 0:
            print('The queue is empty')
            return None
        self.queue.pop(0)
        print(f'Dequeue item: {self.item}')
    
    # Peek the first queue
    def Peek(self) -> Union[int, str]:
        if self.getSize() != 0:
            return self.queue[0]
        return "The queue is empty."

    # Display the queue
    def display(self) -> None:
        print(self.queue)
    

if __name__ == '__main__':
    q = Queue()

    q.enqueu(1)
    q.enqueu(2)
    q.enqueu(3)
    q.enqueu(4)
    q.enqueu(5)

    print()
    print('Queue before dequeuing:')
    q.display()

    print()
    q.dequeue()
    print()

    print('Queue after dequeuing:')
    q.display()
