#include <stdio.h>
#include <stdlib.h>

//Practical no. 4

struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode, *ptr;

void display()
{
    //print list
    printf("list is: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp->next;
    }
    printf("\n");
}

void addsp()
{
    int choice = 1, pos, i;
    //adding a node at specific position
    while(choice)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data value ");
        scanf("%d", &newnode->data);
        printf("Enter position ");
        scanf("%d", &pos);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        }
        else if(pos == 1)
        {
            newnode->next = head;
            head = newnode;
        }
        else 
        {
            temp = head;
            for(i = 2; i < pos; i++)
            {
                temp = temp->next;
            }
            newnode->next = temp -> next;
            temp->next = newnode;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void delsp()
{
    int choice = 1, pos, i;
    //deleting a node at specific position
    while(choice)
    {
        printf("Enter position ");
        scanf("%d", &pos);
        if(head == NULL)
        {
            printf("List is empty\n");
        }
        else if(pos == 1 || head->next == NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            temp = head;
            for(i = 2; i < pos; i++)
            {
                temp = temp->next;
            }
            ptr = temp->next;
            temp->next = ptr->next;
            free(ptr);
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void main()
{
    int choice = 1, opr;
    head = NULL;

    while(choice)
    {
        printf("1: Insert a element at specific position\n");
        printf("2: Delete a element at specific position\n");
        printf("Enter choice ");
        scanf("%d", &opr);
        switch(opr)
        {
            case 1: 
            addsp();
            display();
            break;
            case 2: 
            delsp();
            display();
            break;
            default:
            printf("Invalid case\n");
            break;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    printf("Final ");
    display();
}