#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//Practical no. 6

struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

void add()
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
            temp = newnode;
        } 
        else 
        {
            temp = head;
            while(temp -> next != NULL)
            {
                temp = temp-> next;
            }
            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
    temp->next = head;
}

void disply()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("List is: ");
        temp = head;
        while(temp->next != head)
        {
            printf("%3d", temp->data);
            temp = temp->next;
        }
        printf("%3d", temp->data);
        printf("\n");
    }
}

void main()
{
    
   
        add();
        disply();
           
    
}