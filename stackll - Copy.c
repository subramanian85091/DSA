#include <stdio.h>
#include <stdlib.h>
// Define a node structure
struct Node {
    int data;
    struct Node* next;
};
// Stack structure
struct Stack {
    struct Node* top;
};
// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}
// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}
// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top; // Point new node to the current top
    stack->top = newNode;       // Update the top to the new node
    printf("Pushed %d onto the stack.\n", value);
}
// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot pop.\n");
        return -1; // Return an error value if the stack is empty
    } 
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next; // Update the top to the next node
    free(temp); // Free the popped node
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}
// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    }
    return stack->top->data;
}
// Function to print the stack elements (for debugging or display)
void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack (top to bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    struct Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack); // Output: 30 20 10
    printf("Top element is %d\n", peek(&stack));
    pop(&stack);
    printStack(&stack); // Output: 20 10
    pop(&stack);
    pop(&stack);
    pop(&stack); // Output: Stack is empty! Cannot pop. 
    return 0;
}

