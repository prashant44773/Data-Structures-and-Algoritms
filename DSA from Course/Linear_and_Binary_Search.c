#include <stdio.h>


int BinarySearch(int arr[] , int size , int element)
{
    int low , mid , high ; 

    low = 0 ;
    high = size-1 ;


    while(low <= high)
    {
        mid = (low + high)/2 ;

        if (arr[mid] == element)
        {
            return mid; 
        }
        else if (arr[mid] < element)
        {
            low  = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


int LinearSearch(int arr[], int size , int element)
{
    for (int i = 0 ; i < size ; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int array[] = { 12 , 14 , 34 , 55 , 67 , 77 }; 

    int element = 14 ;

    int size = sizeof(array) / sizeof(int);

    int search = BinarySearch(array,size,element);  // Binary Search Method 

    // int search = LinearSearch(array,size,element);  // Linear Serach Mehod  

    // printf("The size of Array is :  %d",size);

    printf("The Element %d  Found at SearchIndex : %d\n",element,search);

    return 0;
}