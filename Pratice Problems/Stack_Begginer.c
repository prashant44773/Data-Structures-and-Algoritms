#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int peek(struct Stack *str)
{
    return str->arr[str->top];
}

int isEmpty(struct Stack *p)
{
    if (p->top == -1)
    {
        printf("Stack UnderFlow !");
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *p)
{
    if (p->top == p->size)
    {
        printf("Stack OverFlow !");
        return -1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int var)
{
    int a = isFull(ptr);

    if (a == -1)
    {
        printf("Stack OverFlow ! Cannot Push %d in to the Stack\n", var);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = var;
    }
}

int pOp(struct Stack *ptr)
{
    int var;
    int a = isEmpty(ptr);

    if (a == -1)
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        var = ptr->arr[ptr->top];
        ptr->top--;
    }

    return var;
}

struct Stack *NewStack(int cap)
{
    struct Stack *ptr;
    ptr = (struct Stack *)malloc(sizeof(struct Stack));
    ptr->size = cap;
    ptr->top = -1;
    ptr->arr = (int *)malloc(sizeof(int) * cap);
    printf("Stack Created SuccessFully\n");

    return ptr;
}

int main()
{
    struct Stack *var = NewStack(50);
    push(var,45);
    push(var,65);
    push(var,98);
    push(var,59);
    push(var,20);
    push(var,86);

    int num = peek(var);
    printf("The top element is %d\n",num);
    
    int num1 = pOp(var);
    num1 = pOp(var);
    num1 = pOp(var);
    printf("The poped element is %d\n",num1);
    
    int num2 = peek(var);
    printf("The top element is %d\n",num2);
    
    return 0;
}
