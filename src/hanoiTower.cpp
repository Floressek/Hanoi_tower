#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

struct Stack {
    int size;
    int top;
    int* arr;
};

// Function prototypes
Stack* createStack(int size);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
void moveDisk(int disk, char fromPeg, char toPeg);
void moveDiskBetweenPegs(Stack* source, Stack* destination, char s, char d);
void solveTowerOfHanoi(int numberOfDisks, Stack* source, Stack* auxiliary, Stack* destination);
void printStacks(Stack* source, Stack* auxiliary, Stack* destination, int numberOfDisks);

int main() {
    int numberOfDisks;
    cout << "Tower of Hanoi\nEnter the number of disks: ";
    cin >> numberOfDisks;

    if (numberOfDisks > 8) {
        cout << "Maximum allowed disks are 8." << endl;
        return 0;
    }

    Stack* source = createStack(numberOfDisks);
    Stack* auxiliary = createStack(numberOfDisks);
    Stack* destination = createStack(numberOfDisks);

    solveTowerOfHanoi(numberOfDisks, source, auxiliary, destination);

    delete[] source->arr;
    delete source;
    delete[] auxiliary->arr;
    delete auxiliary;
    delete[] destination->arr;
    delete destination;

    return 0;
}

Stack* createStack(int size) {
    auto* stack = new Stack;
    stack->size = size;
    stack->top = -1;
    stack->arr = new int[size];
    return stack;
}

bool isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

void moveDisk(int disk, char fromPeg, char toPeg) {
    cout << "Move disk " << disk << " from peg '" << fromPeg << "' to peg '" << toPeg << "'" << endl;
}

void moveDiskBetweenPegs(Stack* source, Stack* destination, char s, char d) {
    int top1 = pop(source);
    int top2 = pop(destination);

    if (top1 == -1) {
        push(source, top2);
        moveDisk(top2, d, s);
    } else if (top2 == -1) {
        push(destination, top1);
        moveDisk(top1, s, d);
    } else if (top1 > top2) {
        push(source, top1);
        push(source, top2);
        moveDisk(top2, d, s);
    } else {
        push(destination, top2);
        push(destination, top1);
        moveDisk(top1, s, d);
    }
}
void solveTowerOfHanoi(int numberOfDisks, Stack* source, Stack* auxiliary, Stack* destination) {
    char s = 'A', d = 'B', a = 'C';

    if (numberOfDisks % 2 == 0) {
        swap(d, a);
    }

    int totalMoves = pow(2, numberOfDisks) - 1;
    for (int i = numberOfDisks; i >= 1; i--) {
        push(source, i);
    }

    printStacks(source, auxiliary, destination, numberOfDisks);

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1)
            moveDiskBetweenPegs(source, destination, s, d);
        else if (i % 3 == 2)
            moveDiskBetweenPegs(source, auxiliary, s, a);
        else if (i % 3 == 0)
            moveDiskBetweenPegs(auxiliary, destination, a, d);

        printStacks(source, auxiliary, destination, numberOfDisks);
    }
}

void printStacks(Stack* source, Stack* auxiliary, Stack* destination, int numberOfDisks) {
    vector<vector<int>> pegs(3, vector<int>(numberOfDisks, -1)); // -1 denotes an empty spot

    // Fill the vectors with current stack data
    for (int i = 0; i <= source->top; i++) pegs[0][numberOfDisks - i - 1] = source->arr[i];
    for (int i = 0; i <= auxiliary->top; i++) pegs[1][numberOfDisks - i - 1] = auxiliary->arr[i];
    for (int i = 0; i <= destination->top; i++) pegs[2][numberOfDisks - i - 1] = destination->arr[i];

    cout << "Current State:" << endl;
    for (int i = 0; i < numberOfDisks; i++) {
        for (int j = 0; j < 3; j++) {
            if (pegs[j][i] == -1)
                cout << setw(3) << "|" << " ";
            else
                cout << setw(3) << pegs[j][i] << " ";
        }
        cout << endl;
    }
    cout << "----A----B----C----" << endl;
    cout << endl;
}
