#include <stdio.h>

//Practical no. 2

int bin_search(int a[], int n , int key);
 
void main()
{
    int a[20], n, i, key, pos;
    printf("Enter the size of array ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter %d num ", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter a number to search ");
    scanf("%d", &key);
    pos = bin_search(a, n, key);
    if (pos == -1)
    {
        printf("Number not found \n");
        return;
    }
    else
    {
        printf("Number is found at position = %d", pos + 1);
        return;
    }
}

int bin_search(int a[], int n , int key)
{
    int mid , high, low;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low)/2;

        if(a[mid] == key)
        {
            return mid;
        }
        else if(a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid -1 ;
        }
    }

    return -1;
}