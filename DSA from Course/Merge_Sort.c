#include <stdio.h>

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int merge(int A[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

int mergeSort(int A[], int low, int high)
{
    int mid = (low + high) / 2;

    if (low < high)
    {
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int array[] = {3, 6, 4, 1, 2, 9, 0, 8, 7, 5};

    int n = sizeof(array) / sizeof(int);

    display(array, n);

    mergeSort(array,0,n);

    printf("Printing Sorted Array by Merge Sorting...........\n");

    display(array,n);

    return 0;
}