#include <stdio.h>

//Practical no. 1

int lin_search(int a[], int n, int key);

void main()
{
    int a[20], i, pos, key, n;
    printf("Enter the size of array ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter %d num ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter number to search ");
    scanf("%d",&key);
    pos = lin_search(a,n,key);
    if(pos == -1)
    {
        printf("Number does not exist\n");
        return;
    }
    else
    {
        printf("Element found at position = %d", pos+1);
        return;
    }
}

int lin_search(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return(i);
        }
    }
    
    return(-1);
}