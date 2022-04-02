// Stack implementation in C++
// Source: https://www.programiz.com/dsa/stack
#include <stdlib.h>
#include <iostream>

#define MAX 10

int size = 0;

// Creating a stack
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s){
    s->top = -1;
}

// Check if the stack is full
int isFull(st *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if the stack is empty
int isEmpty(st *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Add element(s) into the stack
void push(st *s, int newItem) {
    if (isFull(s))
        std::cout << "Stack is full" << std::endl;
    else {
        s->top++;
        s->items[s->top] = newItem;
        std::cout << "Item pushed: " << newItem << std::endl;
    }

    size++;
}

// Remove element from stack
void pop(st *s) {
    if (isEmpty(s)){
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    
    else {
        std::cout << "Item popped out: " << s->items[s->top] << std::endl;
        s->top--;
    }
    size--;
}

// Peek top value
int peek(st *s) {
    return s->items[s->top];
}

// Print elements of stack
void printStack(st *s) {
    std::cout << "Stack:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << s->items[i] << " ";
    }
    std::cout << std::endl;
}

// Main
int main(){
    int ch;
    st *s = (st *) malloc(sizeof(st));

    createEmptyStack(s);

    for (int i = 1; i < MAX; i++) {
        push(s, i);
    }

    std::cout << "Top element: " << peek(s) << std::endl;

    printStack(s);

    pop(s);

    std::cout << "Top element: " << peek(s) << std::endl;

    std::cout << "\nAfter Popping Out\n";
    printStack(s);
}