#include<stdio.h>

void PrintArray(int A[],int n)
{
    for(int i=0 ; i < n ; i++)
    {
        printf("%d ",A[i]);
    }
}


int InsertionSort(int A[],int n)  // It is Adaptive by Default
{
    int key , j=0;

    for(int i=1 ; i <= n-1 ; i++)
    {
        key = A[i];  

        j = i-1;  

        while(j >= 0   &&  A[j] > key)  
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key; 
    }

}





int main()
{
    int A[] = {34,56,99,25,17,4,66};

    int size = sizeof(A)/sizeof(int);

    PrintArray(A,size);

    InsertionSort(A,size);

    printf("\nThe Sorted Array is \n");
    PrintArray(A,size);




    return 0 ;
}