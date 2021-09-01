#include <stdio.h>

int sort(int arr[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
    }

    // printf("\nThe Number of Times Zero Repeats itself in the Array is  :  %d\n", count);

    int k = 0, l;

    while (count--)
    {
        arr[k] = 0;

        k++;
    }

    // printf("\nThe Number of Times Zero Assigned to the Array is  :  %d\n", k);

    // for (int i = 0; i < k; i++)
    // {
    //     printf("The value stored in arr[%d]  is  :  %d\n",i,arr[i]);

    //     l = k;
    // }

    while (k < size)
    {
        arr[k] = 1;

        k++;
    }

    // printf("\nThe  Value Strored in this Second Array is :   \n");

    // for (int i = l; i < size; i++)
    // {
    //     printf("The value stored in arr[%d]  is  :  %d\n",i,arr[i]);
    // }
}

int main()
{
    int arr[] = {0, 1, 0, 0, 0, 1, 0, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr, size);

    // printf("The Size of Array is  :   %d",size);

    for(int j=0 ; j < size ; j++)
    {
        printf("%d ",arr[j]);
    }

    return 0;
}