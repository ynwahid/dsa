// Queue implementation in CPP
// Source: https://www.programiz.com/dsa/queue
#include <iostream>
#define SIZE 5

class Queue {
    private:
        int items[SIZE];
        int front;
        int rear;
    
    public:
        Queue() {
            this->front = -1;
            this->rear = -1;
        }

        bool isFull(){
            if (this->front == 0 && this->rear == SIZE - 1)
                return true;
            else
                return false;
        }

        bool isEmpty(){
            if (this->front == -1)
                return true;
            else
                return false;
        }

        void enQueue(int element){
            if (this->isFull())
                std::cout << "Queue is full!";
            else {
                if (this->front == -1)
                    this->front = 0;

                this->rear++;
                this->items[rear] = element;
                std::cout << "Queued: " << element << std::endl;
            }
        }

        int deQueue() {
            int element;
            
            if (this->isEmpty()){
                std::cout << "Queue is empty!" << std::endl;
                return -1;
            }

            else {
                element = this->items[front];
                if (this->front == this->rear) {
                    this->front = -1;
                    this->rear = -1;
                }

                else {
                    this->front++;
                }

                std::cout << std::endl << "Deleted: " << element << std::endl;
                return element;
            }
        }

        int peek() {
            return this->items[this->front];
        }

        void display() {
            if (this->isEmpty())
                std::cout << "Empty Queue" << std::endl;
            else {
                std::cout << "Front index: " << this->front << std::endl;
                std::cout << "Items:" << std::endl;

                for (int i = this->front; i <= rear; i++)
                    std::cout << this->items[i] << " ";
                
                std::cout << std::endl;
                std::cout << "Rear index: " << this->rear << std::endl;
            }
        }
};

int main() {
    Queue queue;

    // Dequeue is not possible on empty queue
    queue.deQueue();

    // Enqueue 5 elements
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    queue.enQueue(4);
    queue.enQueue(5);

    // 6th element cant be added to because the queue is full
    queue.enQueue(6);

    queue.display();

    // Dequeue removes element entered first i.e. 1
    queue.deQueue();

    // Now we have just 4 elements
    queue.display();

    return 0;
}