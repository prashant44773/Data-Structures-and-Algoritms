#include<stdio.h>
#include<stdlib.h>



struct Stack 
{
    int size;
    int Top;
    char *arr;
};


int isFull(struct Stack *q)
{
    if(q->Top == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int isEmpty(struct Stack *q)
{
    if(q->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



char Push(struct Stack *p , char ch)
{
    if(isFull == 1)
    {
        printf("Stack OverFlow ! Cannot Push  %c",ch);
    }
    else
    {
        p->Top++;

        p->arr[p->Top] = ch;
    }

}


char pop(struct Stack *p)
{
    if(isEmpty == 1)
    {
        printf("Stack UnderFlow !\n");
    }
    else
    {
        char val;

        val = p->arr[p->Top];
        p->Top--;

        // return val;
    }
}



int Paranthesis(char *exp)
{
    struct Stack *ptr;

    ptr->size = 10;

    ptr->Top = -1;

    ptr->arr = (char *)malloc(ptr->size * sizeof(char)); 

    for(int i=0 ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(')
        {
            Push(ptr,'(');
        }
        else if(exp[i] == ')')
        {
            if(isEmpty(ptr) == 1)
            {
                return -1;
            }

            pop(ptr);
        }
    }

    if(isEmpty(ptr) == 1)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}


//.........................................................................................//


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



//..........................................................................................//


int main()
{
    int a ;

    char *exp = "9*4 + (0 +)- ((7)";

    // a = Paranthesis(exp);

    // printf("The Value of a is :  %d",a);




    if(Paranthesis(exp) == 0)
    {
        printf("\nThe Parenthesis Balanced\n\n");
    }
    else
    {
        printf("\nThe Parenthesis Not Balancsd\n\n");
    }


    return 0 ;
}