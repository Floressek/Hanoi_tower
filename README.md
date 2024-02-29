# Tower of Hanoi

This is a C++ implementation of the classic Tower of Hanoi problem. The program takes in the number of disks to be moved and solves the problem using recursive moves.

## Functionality

* `createStack()`: Creates a new stack with the given size.
* `isFull()`: Returns true if the stack is full, false otherwise.
* `isEmpty()`: Returns true if the stack is empty, false otherwise.
* `push()`: Pushes an item onto the stack.
* `pop()`: Removes and returns the top item from the stack.
* `moveDisk()`: Moves a disk from one peg to another.
* `solveTowerOfHanoi()`: Solves the Tower of Hanoi problem using recursive moves.
* `printStacks()`: Prints the current state of the stacks.

## Implementation

The program uses three stacks: `source`, `auxiliary`, and `destination`. The `solveTowerOfHanoi()` function takes in the number of disks to be moved, the `source` stack, the `auxiliary` stack, and the `destination` stack. It then solves the problem using recursive moves, printing the current state of the stacks at each step.

The `moveDisk()` function moves a disk from one peg to another. The `printStacks()` function prints the current state of the stacks, with the disks represented as integers on the pegs.

## Testing

To test this program, simply run it and enter the number of disks to be moved. The program will then solve the problem and print the current state of the stacks at each step.

Note: This program only supports moving a maximum of 8 disks.
