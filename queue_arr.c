#include<stdio.h>
#include<stdlib.h>

int arr[100];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == 99)
    {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    arr[rear]=x;
}

void dequeue()
{
    if (front == rear)
    {
        printf("Queue Underflow\n");
        return;
    }

    front++;
    printf("Deleted: %d\n", arr[front]);
}

void display()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}



int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}