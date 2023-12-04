#include <stdio.h>
#include <stdlib.h>

//Practical no. 7b

struct node
{
    int data; 
    struct node *next;
};
struct node *top = NULL;
void PUSH(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void PoP()
{
    struct node *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("enpty stack");
    }
    else
    {
        printf("PoP out element = %d ", temp->data);
        top = temp->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = top;
    if (temp == NULL)
    {
        printf("empty stack");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
}
void main()
{
    int a, b, x;
    b = 1;
    while (b)
    {
        printf("enter your option\n");
        printf("1:push,2:pop,3:display\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("enter the value of push ");
            scanf("%d", &x);
            PUSH(x);
            break;
        case 2:
            PoP();
            break;
        case 3:
            display();
            break;
        }
        printf("do you want to continue:1/0  ");
        scanf("%d", &b);
    }
}