#include <stdio.h>

int stack[100];
int top = -1;
int n;

void push(int x)
{
    if (top == n)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted: %d\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

int main()
{
    printf("Enter stack size: ");
    scanf("%d", &n);

    push(10);
    push(20);
    push(30);

    peek();

    pop();

    peek();

    return 0;
}