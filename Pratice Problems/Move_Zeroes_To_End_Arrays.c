#include <stdio.h>

int PrintArray(int arr[], int size)
{
    printf("\nThe Array is :\t");

    for(int i=0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
}


int MoveToEnd(int arr[], int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[j++] = arr[i];
        }
    }

    // printf("\nThe value of J is : %d\n", j);

    for (int r = j ; r < size ; r++)
    {
        arr[r] = 0;
    }
}

int main()
{
    int arr[] = {2, 0, 7, 0, 3, 1, 0, 9};

    int size = sizeof(arr) / sizeof(int);

    PrintArray(arr,size);

    MoveToEnd(arr, size);

    printf("\n");

    PrintArray(arr,size);

    return 0;
}