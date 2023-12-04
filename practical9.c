#include <stdio.h>
#include <stdlib.h>

//Practical no. 9

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*root = NULL;

void insert(int item)
{
    struct node *ptr, *parent, *nodeptr;
    ptr = malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("Can't insert\n");
    }
    else
    {
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        if(root == NULL)
        {
            root = ptr;
            root->left = NULL;
            root->right = NULL;
        }
        else
        {
            parent = NULL;
            nodeptr = root;
            while(nodeptr != NULL)
            {
                parent = nodeptr;
                if(item < nodeptr->data)
                {
                    nodeptr = nodeptr->left;
                }
                else
                {
                    nodeptr = nodeptr->right;
                }
            }
            if(item < parent->data)
            {
                parent->left = ptr;
            }
            else
            {
                parent->right = ptr;
            }
        }
    }
}

void inorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{ 
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void main()
{
    int item, choice = 1, opr;
    while(choice)
    {
        printf("Enter your option\n");
        printf("1.Insert 2.Preorder 3.Inorder 4.Postorder ");
        scanf("%d", &opr);
        switch(opr)
        {
            case 1:
                printf("Enter the data ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                postorder(root);
                break;
            default:
                printf("Invalid case\n");
                break;
        }
        printf("Enter your choice 1/0: ");
        scanf("%d", &choice);
    }
}