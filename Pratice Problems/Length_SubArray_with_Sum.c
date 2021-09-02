#include <stdio.h>

void Equillibrium(int arr[], int size, int sum)
{
    // Starting Index of Sub-aaray's Lengthen

    int Startlen = 0, Endlen = 0, Maxlen = 0;

    for (int i = 1; i < size; i++)
    {
        int Target = 0;

        for (int j = i; j < size; j++)
        {
            Target += arr[j]; // Target = Target + arr[j];

            // printf("The value of      i is %d        j is %d      Target is  %d     Value of last arr[%d] is  %d\n", i, j, Target ,j,arr[j]);

            if (Target == sum)
            {
                // printf("Success!\t\t");
                // printf("At value of  i  is  %d  and j  is  %d\n", i, j);

                // Sub-Array's Starting Point is i and Ending is j  and
                // printf("\nThe Array starts From arr[%d]  and Ends at arr[%d]  is :  %d\n\n", i, j ,Target);  

                if(Maxlen < j - i)
                {
                    Startlen = i;

                    Endlen = j;

                    Maxlen = j - i;

                    // printf("The Value of   Startlen is  %d    Endlen is  %d   AND   Maxlen is  %d\n", i, j, Maxlen);

                }
            }
        }

    }

        printf("the value of  Startlen is %d   Endlen is %d\n",Startlen, Endlen);


}

int main()
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};

    int size, Target;

    size = sizeof(arr) / sizeof(arr[0]);

    Target = 8;

    Equillibrium(arr, size, Target);

    return 0;
}