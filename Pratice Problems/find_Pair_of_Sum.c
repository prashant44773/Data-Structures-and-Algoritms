#include<stdio.h>

void Find_Pair(int arr[] , int Rounds , int Target)
{
    for(int i=0 ; i < Rounds ; i++)
    {
        for(int j=1 ; j < Rounds ; j++)
        {
            if(arr[i] + arr[j] == Target && arr[i] != arr[j])
            {
                printf("\narr( %d , %d ) == %d\n",arr[i],arr[j],Target);
                // return 0;
            }
        }
    }

}

int main()
{
    int arr[] = {2 , 3 , 6 , 5 , 11 , 22 , 44 , 4 , 12 , 15 , 1 , 5 , 7};

    int Target = 10;

    int n = sizeof(arr) / sizeof(int);

    Find_Pair(arr,n,Target);

    return 0 ;
}