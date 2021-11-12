# Stack Implementation in Python
# source: https://www.programiz.com/dsa/stack
from typing import Union

# Creating a stack
def create_stack() -> list:
    stack = []
    return stack

# Check if the stack is empty
def check_empty(stack: list) -> bool:
    return len(stack) == 0

# Adding item(s) into the stack
def push(stack: list, item) -> list:
    stack.append(item)
    print(f'{item} is pushed into stack.')
    print(f'Stack after pushing: {stack}')
    return stack

# Remove an element from stack
def pop(stack: list) -> Union[list, str]:
    if check_empty(stack):
        return 'stack is empty'
    
    return stack.pop()

if __name__ == "__main__":
    stack = create_stack()
    push(stack, 1)
    push(stack, 2)
    push(stack, 3)
    push(stack, 4)
    
    for i in range(len(stack)):
        print(f'Popped item: {pop(stack)}')
        print(f'Stack after popping: {stack}')