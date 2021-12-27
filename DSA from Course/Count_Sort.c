#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Traversal(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int A[], int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }

    return max;
}

int count_sort(int A[], int n)
{
    int i, j;
    // To get the maximum number from the Array......
    int max = maximum(A, n);

    // Allocating the Memory Dynamically...............

    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initializing the elements of count Array to 0

    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    //......Important Step........//

    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    //...Counters...//

    i = 0; // Conter for count Array
    j = 0; // Conter for main Array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int A[] = {4, 3, 1, 8, 0, 6, 7, 2, 9};

    int n = sizeof(A) / sizeof(int);
    
    Traversal(A,n);
    count_sort(A, n);
    Traversal(A,n);

    return 0;
}