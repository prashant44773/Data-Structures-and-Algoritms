#include <stdio.h>

int merg[];

int Glen; 

int Sort(int arr[], int len)
{
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                int tmp;

                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    Glen = len;

    for (int p = 0; p <= len; p++)
    {
        merg[p] = arr[p];
    }

}


void re_arrange_and_Merge(int arrf[], int arrsec[2], int m, int n)
{
    int array1[m], array2[n];
    int i = 0, j = 0;

    while (i != m)
    {
        if (arrf[i] != 0)
        {
            array1[j] = arrf[i];
            j++;
        }
        i++;
    }

    int length, l = 0, v = 0;

    length = j + n;

    int Merged[length];

    while (l != length + 1)
    {
        if (l < j)
        {
            Merged[l] = array1[l];
            l++;
        }

        if (l == j)
        {
            l++;
        }

        if (l > j)
        {
            int q;
            q = l - 1;
            Merged[q] = arrsec[v];
            v++;
            l++;
        }
    }

    length = length - 1;

    Sort(Merged, length);
}

int main()
{
    int arr1[] = {0, 3, 6, 0, 7, 8, 0 , 0, 10 , 0 , 11 , 14 , 0 , 0};
    int arr2[] = {1, 9 , 2 , 13 , 12};

    int m, n;

    m = sizeof(arr1) / sizeof(arr1[0]);
    n = sizeof(arr2) / sizeof(arr2[0]);

    re_arrange_and_Merge(arr1, arr2, m, n);

    printf("\n");

    printf("The final Array is : \t");

    for (int i = 0; i <= Glen; i++)
    {
        printf("%d ",merg[i]);
    }

    return 0;
}