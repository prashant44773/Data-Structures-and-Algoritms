#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size)
    {
        printf("\nStack is FULL\n");
        return -1;
    }
    else
    {
        return 0;
    }
}


int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        printf("\nStack UnderFlow\n");
        return -1;
    }
    else
    {
        return 0;
    }
}


char pop(struct stack *ptr)
{
    char var;

    if(isEmpty(ptr) == -1)
    {
        return -1;
    }
    else
    {
        var = ptr->arr[ptr->top];
        ptr->top--;
    }
    return var;
}



void push(struct stack *ptr , char var)
{

    if(isFull(ptr) == -1)
    {
        return -1;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = var;
    }
}



char peek(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}



int Match(char sigma , char alpha)
{
    if(sigma == '('  &&  alpha == ')')
    {
        return 0;
    }
    else if(sigma == '['  &&  alpha == ']')
    {
        return 0;
    }
    else if (sigma == '{'  &&  alpha == '}')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



char checkIfParanthesisBalance(char *exp)
{

}




int main()
{ 

    return 0;
}