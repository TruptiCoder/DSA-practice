#include <stdio.h>
#include <stdlib.h>

//Practical no. 3

struct node
{
    int data;
    struct node* next;
};
struct node *head, *newnode, *temp, *ptr;

void addfisrt()
{
    int choice = 1;
    //adding a node at beginning
    while (choice)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter the data value ");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void addend()
{
    int choice = 1;
    //adding node at end
    while (choice)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter data value ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
        } 
        else
        {
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp-> next;
            }
            temp->next = newnode;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void delfirst()
{
    int chk =1;
    //deleting first node
    while (chk)
    {
        if(head == NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            temp = head;
            head = head->next; 
            free(temp);
        }
        printf("Enter choice: ");
        scanf("%d", &chk);
    }
}

void delend()
{
    int chk = 1;
    //deleting last node
    while(chk)
    {
        if(head == NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            ptr = temp -> next;
            temp -> next = NULL;
            free(ptr);
        }
        printf("Enter choice: ");
        scanf("%d", &chk);
    }
}

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

void main()
{
    int choice = 1, opr;
    head = NULL;
    while (choice)
    {
        printf("1: add node at beginning\n");
        printf("2: add node at end\n");
        printf("3: del first node\n");
        printf("4: del last node\n");
        printf("Enter choice: ");
        scanf("%d", &opr);
        switch(opr)
        {
            case 1:
            addfisrt();
            display();
            break;
            case 2:
            addend();
            display();
            break;
            case 3:
            delfirst();
            display();
            break;
            case 4: 
            delend();
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