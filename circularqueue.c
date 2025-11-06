#include <stdio.h>
#define CAP 10
int queue[CAP];
int front = -1;
int rear = -1;
int isfull()
{
    return (rear + 1) % CAP == front;
}

int isempty()
{
    return front == -1;
}

void enqueue(int data)
{
    if (isfull())  
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % CAP;
    queue[rear] = data;
    printf("Inserted element: %d\n", data);
}

int dequeue()
{
    if (isempty())  
    {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    printf("Dequeued: %d\n", data);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % CAP;
    }
    return data;
}

void display()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % CAP;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    int val = dequeue();
    printf("Dequeued element: %d\n", val);
    display();
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}
