#include <stdio.h>
#include <stdlib.h>

//Practical no. 5

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head, *tail, *temp, *newnode;
 

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

void addfirst()
{
    int choice = 1;
    while(choice)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter the data ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = head;
        head = newnode;
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void addend()
{
    int choice = 1;
    while(choice)
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter the data ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            newnode->prev = temp;
            temp->next = newnode;
            tail = newnode;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void delfirst()
{
    int choice = 1;
    while(choice)
    {
        if(head == NULL)
        {
            printf("List is empty \n");
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

void delend()
{
    int choice = 1;
    while(choice)
    {
        if(head == NULL)
        {
            printf("List is empty\n");
        }
        else if(head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            tail = head;
            while(tail->next->next != NULL)
            {
                tail = tail->next;
            }
            temp = tail->next;
            tail->next = NULL;
            free(temp);
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
}

int main()
{
    int choice = 1, opr;
    head = NULL;
    while(choice)
    {
        printf("1: Insert at beginning\n");
        printf("2: Insert at end\n");
        printf("3: Delete first node\n");
        printf("4: Delete last node\n");
        printf("Enter choice: ");
        scanf("%d", &opr);
        switch(opr)
        {
            case 1:
            addfirst();
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
        scanf("%d",&choice);
    }
    printf("Final ");
    display();
}