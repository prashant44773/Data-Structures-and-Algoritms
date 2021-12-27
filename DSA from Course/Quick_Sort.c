#include <stdio.h>


void display(int A[] , int var)
{
    printf("Printing the array..............\n");
    for(int i=0 ; i < var ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
} 



int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    int temp;

    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

int quickSort(int A[], int low, int high)
{
    int partitionIndex ; 

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {3, 2, 8, 6, 1, 7, 4, 9, 0, 5};

    int n = sizeof(A) / sizeof(int);

    // printf("The Size of Array is %d\n",n);
    
    display(A,n);
    quickSort(A,0,n);
    display(A,n);
    return 0;
}