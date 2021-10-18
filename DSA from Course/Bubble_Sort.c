#include <stdio.h>

void PrintArray(int A[], int n)
{
    printf("\nThe Array is  : \t");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void BubbleSortAdaptive(int A[], int n)
{
     int temp , count=0;

    for (int i = 0; i < n - 1; i++)
    {
        printf("Number of Passes : %d\n", i+1);
        
        count = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

                count = 0;
            }
        }

        if(count == 1)
        {
            return;
        }
    }
}

void BubbleSort(int A[], int n)
{
    int temp ;

    for (int i = 0; i < n - 1; i++)   // Number of Passess
    {
        for (int j = 0; j < n - 1 - i; j++)  // Number of Comparisons
        {
            if (A[j] > A[j + 1])  
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // int A[] = {7, 4, 6, 2, 5, 1, 8, 3};
    int A[] = {1,2, 3, 4, 5, 6, 7, 8};

    int size = sizeof(A) / sizeof(int);

    printf("\nThe Array Before Sorting\n");

    PrintArray(A, size);

    printf("\n\nThe Array After Sorting\n");

    BubbleSort(A, size);

    PrintArray(A, size);

    // printf("The Value of Size is :  %d",size);

    return 0;
}