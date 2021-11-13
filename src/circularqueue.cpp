// Circular Queue implementation in Cpp
// Source: https://www.programiz.com/dsa/circular-queue
#include <iostream>
#define SIZE 5 /* Size of circular queue */

class CircularQueue {
    private:
        int items[SIZE];
        int front;
        int rear;

    public:
        CircularQueue(){
            this->front = -1;
            this->rear = -1;
        }

        // Check if the queue is full
        bool isFull(){
            if (this->front == 0 && this->rear == SIZE - 1)
                return true;
            if (this->front == this->rear + 1)
                return true;
            return false;
        }

        bool isEmpty(){
            if (this->front == -1)
                return true;
            return false;
        }


        // Adding an element
        void enQueue(int element){
            if (this->isFull())
                std::cout << "Queue is full!" << std::endl;
            else {
                if (this->front == -1)
                    this->front = 0;
                this->rear = (this->rear + 1) % SIZE;
                this->items[rear] = element;
                std::cout << "Inserted: " << element << std::endl;
            }
        }

        // Removing an element
        void deQueue() {
            if (this->isEmpty())
                std::cout << "Queue is empty!" << std::endl;
            else {
                int element = this->items[this->front];
                if (this->front == this->rear) {
                    this->front = -1;
                    this->rear = -1;
                }
                else {
                    this->front = (front + 1) % SIZE;
                }
                std::cout << "Dequeued: " << element << std::endl;
            }
        }

        // Peeking front element
        void peek(){
            if (this->isEmpty())
                std::cout << "Queue is empty!" << std::endl;
            else
                std::cout << "Front item: "<< this->items[this->front] << std::endl;
        }

        // Display Queue
        void display() {
            if (this->isEmpty())
                std::cout << "Queue is empty!" << std::endl;
            else {
                std::cout << "Items: ";
                if (this->rear >= this->front) {
                    for (int i = this->front; i != (this->rear + 1) % SIZE; i = (i + 1) % SIZE)
                        std::cout << this->items[i] << " ";
                }
                
                else {
                    for (int i = this->front; i < SIZE; i++)
                        std::cout << this->items[i] << " ";
                    for (int i = 0; i < this->rear + 1; i++)
                        std::cout << this->items[i] << " ";
                }

                std::cout << std::endl;
                std::cout << "Front index: " << this->front << std::endl;
                std::cout << "Rear index: " << this->rear << std::endl;
            }
        }
};

int main() {
    CircularQueue queue;

    // Fails because front = -1
    queue.deQueue();

    // Adding elements to queue
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);

    // Fails to enqueue because front == 0 && rear == SIZE - 1
    queue.enQueue(6);

    // Remove an element from queue
    queue.deQueue();

    // Display
    queue.display();

    // Adding an element again to queue
    queue.enQueue(7);

    // Display
    queue.display();

    // Fails to enqueue because front == rear + 1
    queue.enQueue(8);

    // Peeking front element
    queue.peek();

    return 0;
}