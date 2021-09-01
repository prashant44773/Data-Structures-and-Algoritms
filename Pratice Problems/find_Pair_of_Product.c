#include<stdio.h>

void findMaximumProduct(int arr[] , int n)
{

    int Max = 0;

    int max_i , max_j ;


    if(n < 2)
    {
        return ;
    }

    for(int i=0 ; i < n-1 ; i++)
    {
        for(int j=1 ; j < n ; j++)
        {
            if(arr[i] * arr[j] > Max && arr[i] != arr[j]) 
            {
                Max = arr[i] * arr[j];

                max_i = arr[i];

                max_j = arr[j];
            }
        }
    }

    printf("\nThe Pair with highest Product is  :  arr(%d,%d)\n",max_i,max_j);
}



int main()
{
    int arr[] = {3 , 5 , -2 , -10 , -5 , 6};

    int n = sizeof(arr) / sizeof(int);

    // printf("The Size of arr is :  %d\n",n);

    findMaximumProduct(arr,n);


    return 0 ;
}