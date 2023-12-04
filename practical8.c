#include <stdio.h>
#include <conio.h>
#define max 10
int list[max];
int front = -1;
int rear = -1;

//Practical no. 8

void enque(void);
int deque(void);
void display(void);

void main()
{
    int option, val;
    do
    {
        printf("1:Insert 2:Delete 3:Display 4:Exit ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enque();
            break;
        case 2:
            val = deque();
            if (val == -1)
            {
                return;
            }
            printf("%d ", val);
            break;
        case 3:
            display();
            break;
 
        default:
            break;
        }
    } while (option != 4);
}

void enque(void)
{
    int data;
    if (rear == max - 1)
    {
        printf("overflow\n");
        return;
    }
    else
    {
        printf("Enter the data ");
        scanf("%d", &data);
        if (rear == -1 && front == -1)
        {
            rear = 0;
            front = 0;
        }
        else
        {
            rear = rear + 1;
        }
        list[rear] = data;
    }
}

int deque(void)
{
    int data;
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        data = list[front];
        front++;
    }
    return (data);
}

void display(void)
{
    int temp;
    if (front == -1 || front > rear)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = front;
        while (temp <= rear)
        {
            printf("%3d", list[temp]);
            temp++;
        }
        printf("\n");
    }
}