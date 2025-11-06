#include <stdio.h>
#define CAP 3

int stack[CAP];
int top = -1;

 void push(int data)
 {
 if (top>=CAP -1)
 {
 printf("Stack Overflow!\n");
 }
 else
 {
 top++;
 stack[top] = data;
 printf("%d pushed to stack.\n",data);
 }
 }
 int pop(int data) {
 int p;
    if (top==-1)
    {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    else
    p=stack[top];
    top--;
    printf("The popped Element:%d\n",p);

}
void peek()
{
    int e;
    if (top==-1)
        printf("The Stack is Empty.\n");

    else
    stack[top]=e;
    printf("The Top element:%d\n",e);

}
int isFull()
{
    if (top==CAP-1)
        printf("The stack is full!");
    else
        printf("The stack is not full");
}
int isEmpty()
{
    if(top==-1)
    printf("\nthe stack is empty");
}
int main()
{
    push(10);
    push(20);
    push(30);
    pop(30);
    peek();
    isFull();
    isEmpty();
    return 0;
 }

