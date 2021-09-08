#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;

    int *arr;
};

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        // printf("\nStack Overflow !\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        // printf("\nStack Underflow !\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    int a;

    a = isfull(ptr); // if its 1 then Overflow

    if (a == 1)
    {
        printf("\nStack Overflow ! Cannot Push  %d \n", value);
    }
    else
    {
        ptr->top++;

        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    int b, var;

    b = isEmpty(ptr);

    if (b == 1)
    {
        printf("\nStack Underflow ! The Stack is Empty\n");
    }
    else
    {
        var = ptr->arr[ptr->top];

        ptr->top--;

        return var;
    }
}



int peek(struct stack *ptr , int ind)
{
    int positionInStack ;

    positionInStack = ptr->top -ind +1 ;

    if (positionInStack < 0)
    {
        printf("\nNot A Valid Option for the Stack\n");
    }
    else
    {
        return ptr->arr[positionInStack];
    }

}



int Stack_Top(struct stack *p)
{
    return p->arr[p->top];
}




int Stack_Bottom(struct stack *p)
{
    return p->arr[0];
}






int main()
{
    int check1, check2;

    struct stack *str;

    str = (struct stack *)malloc(sizeof(struct stack));

    str->size = 10;
    str->top = -1;

    str->arr = (int *)malloc(str->size * sizeof(int));

    check1 = isfull(str);
    check2 = isEmpty(str);

    printf("\nThe value of isfull is %d\n", check1);
    printf("\nThe value of isEmpty is %d\n\n", check2);

    push(str, 34);
    push(str, 10);
    push(str, 94);
    push(str, 67);
    push(str, 20);
    push(str, 66);

    // int k;

    // k = pop(str);
    // printf("\nThe Element that we have Popped is :  %d\n", k);

    // k = pop(str);
    // printf("\nThe Element that we have Popped is :  %d\n", k);


    // for(int i=1 ; i <= str->top + 1 ; i++)
    // {
    //     printf("The Value at %d Position is  :  %d\n",i,peek(str,i));
    // }



    printf("\nThe Value at the Bottom of Stack is  :  %d\n",Stack_Bottom(str));

    printf("\nThe Value at the TOP of Stack is  :  %d\n",Stack_Top(str));



    check1 = isfull(str);
    check2 = isEmpty(str);

    printf("\nThe value of isfull is %d\n", check1);
    printf("\nThe value of isEmpty is %d\n", check2);

    return 0;
}