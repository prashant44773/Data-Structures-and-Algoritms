#include <stdio.h>

// int swap(int a , int b)
// {
//     int temp;

//     temp = a ;
//     a = b;
//     b = temp;
// }

void DisplayArray(int Array[], int size)
{
    int i;

    for (i = 0; i <= size - 1; i++)
    {
        printf("%d ", Array[i]);
    }

    printf("\n");
}

int Selection_Sort(int array[], int n)
{
    printf("Printing Selection sort array........\n");

    int IndexofMin, j, i;

    for (i = 0; i <= n - 1; i++)
    {
        IndexofMin = i;

        for (j = i + 1; j <= n - 1; j++)
        {
            int temp;

            if (array[i] > array[j])
            {
                // swap(&array[i] , &array[j]);
                // // swap(array[i] , array[j]);

                int temp ;

                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {4, 3, 8, 1, 9 , 45 , 88 , 12 , 0 , 1087 ,  33 , 99};

    int n = sizeof(A) / sizeof(int);

    // printf("The size of array is  :  %d\n",n);

    DisplayArray(A, n);

    Selection_Sort(A, n);

    DisplayArray(A, n);

    return 0;
}