#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x)
{
    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = top;

    top = newNode;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;

    printf("Deleted: %d\n", top->data);
    top=top->next;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

int main()
{
    push(10);
    push(20);
    push(30);

    peek();

    pop();
    push(5);

    peek();

    return 0;
}