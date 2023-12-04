#include <stdio.h>
#define N 5
int stack[N];
int top = -1;

//Practical no. 7a

void push()
{
    int x, choice = 1;
    while (choice)
    {
        printf("Enter the data ");
        scanf("%d", &x);
        if (top == N - 1)
        {
            printf("overflow");
            return;
        }
        else
        {
            top++;
            stack[top] = x;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void pop()
{
    int item, choice=1;
    while (choice)
    {
        if (top == -1)
        {
            printf("underflow");
            return;
        }
        else
        {
            item = stack[top];
            printf("%d", item);
            top--;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void display()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf("%d  ", stack[i]);
    }
    printf("\n");
}

void main()
{
    int a, b, x;
    b = 1;
    while (b)
    {
        printf("Enter your options \n");
        printf("1. Push 2.Pop 3.display\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            push();
            break;
        case 2: 
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid choice\n");
        }

        printf("Do you want to contine ");
        scanf("%d", &b);
    }
}