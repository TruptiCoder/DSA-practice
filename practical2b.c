#include <stdio.h>

int binrec(int arr[], int n, int key, int low , int high);

void main()
{
    int arr[20], n, key, pos, low, high, i;
    printf("Enter the size of array ");
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter the %d element in ascending order ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the key ");
    scanf("%d", &key);
    low = 0;
    high = n-1;
    pos = binrec(arr, n, key, low, high);
    if(pos == -1) 
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index = %d \n", pos);
    }
}

int binrec(int arr[], int n, int key, int low , int high)
{
    int mid;
    mid = (low+high)/2;
    if(low > high)
    {
        return -1;
    }
    if (arr[mid] == key)
    {
        return (mid);
    }
    else if(key > arr[mid])
    {
        low = mid + 1;
        return(binrec(arr, n, key, low, high));
    }
    else
    {
        high = mid - 1;
        return(binrec(arr, n, key, low, high));
    }
}