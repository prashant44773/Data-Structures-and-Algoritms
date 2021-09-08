#include <stdio.h>

void Traversal(int ary[], int size) // Traversal Function
{
    for (int j = 0; j < size; j++)
    {
        printf(" %d ", ary[j]);
    }
}

int Insertion(int capacity, int arr[], int size, int ind, int element) // Insertion Function
{

    if (size > capacity)
    {
        return -1;
    }

    for(int r = size-1 ; r >= ind ; r--)
    {
        arr[r+1] = arr[r];
    }
    arr[ind] = element ;

    printf("\nSuccessfully Ran\n");

    return 1;
}

int Deleteion(int capacity, int arr[], int size, int ind) // Deletion Function
{
    if (ind > size)
    {
        return -1;
    }
    for (int i = ind; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    return 1;
}

int main()
{
    int index = 3;

    int element = 34;

    int array[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int size = 10, capacity = 100;

    printf("The Array before Modification : \n");

    Traversal(array, size);

    printf("\n");

    // Deleteion(capacity, array, size, index);

    // //..............Deletion of Array..............//

    // printf("The Array After deletion is : \n");

    // size -= 1;

    // Traversal( array , size );

    //...........Insertion OF Array................//

    printf("The Array After Insertion is : \n");

    size += 1;

    Insertion(capacity, array, size, index, element);

    // int result = Insertion(capacity,array,size,index,element);

    // printf("The Value of Result is : %d\n",result);

    Traversal( array , size);

    return 0;
}