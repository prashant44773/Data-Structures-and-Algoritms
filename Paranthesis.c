#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int Top;
    char *arr;
};

int isFull(struct Stack *p)
{
    if (p->Top == p->size - 1)
    {
        printf("\nStack OverFlow !\n");
        return -1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *p)
{
    if (p->Top == -1)
    {
        // printf("\nStack UnderFlow !\n");

        return -1;
    }
    else
    {
        return 0;
    }
}

void Push(struct Stack *p, char ch)
{
    if (isFull(p) == -1)
    {
        printf("\nStack OverFlow !\n");
    }
    else
    {
        struct Stack *add;

        add = (struct Stack *)malloc(sizeof(struct Stack));

        add->Top++;

        add->arr[add->Top] = ch;
    }
}

char Pop(struct Stack *ptr)
{
    if (isEmpty(ptr) == -1)
    {
        printf("\nStack UnderFlow !\n");
    }
    else
    {
        char var;

        var = ptr->arr[ptr->Top];

        ptr->Top--;

        return var;
    }
}

//......................................................................................//

int Parenthesis(char * exp)
{
    struct Stack *str;

    str->size = 20;

    str->Top = -1;

    str->arr =  (char *)malloc(str->size * sizeof(char));

    for(int i=0 ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(')
        {
            Push(str,'(');
        }
        else if (exp[i] == ')')
        {
            if(isEmpty(str) == -1)
            {
                return 0;
            }
            Pop(str);
        }
    }


    if(isEmpty(str) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}





//......................................................................................//


// char Peek(struct Stack *q , int ind)
// {
//     int PositionInStack ;

//     PositionInStack = q->Top - ind + 1 ;

//     if(PositionInStack < 0)
//     {
//         printf("\nInvallid Position ! \n");
//     }
//     else
//     {
//         char ch;

//         ch = q->arr[PositionInStack] ;

//         return ch;

//     }
// }






int main()
{

    char * exp =  "(2*3) + (23-9)";


    int var = Parenthesis(exp);

    printf("The Value of Var is  %d\n",var);


    if(Parenthesis(exp) == 0)
    {
        printf("\nThe Parenthesis Does Not Match\n\n");
    }
    // else if(Parenthesis(exp) == 1)
    else
    {
        printf("\nThe Parenthesis Matched\n\n");
    }





//....................................................................................//    
    // struct Stack *str;

    // str = (struct Stack *)malloc(sizeof(struct Stack));

    // str->size = 20;

    // str->Top = -1;

    // printf("The isFull Value is : %d\n", isFull(str));
    // printf("The isFull Value is : %d\n", isEmpty(str));

    // Push(str, 'w');
    // Push(str, 'e');

    // for(int i = 0 ; i < 2 ; i++)
    // {
    //     printf("%c ",Peek(str,i));
    // }

    // printf("The isFull Value is : %d\n", isFull(str));
    // printf("The isFull Value is : %d\n", isEmpty(str));

    return 0;
}