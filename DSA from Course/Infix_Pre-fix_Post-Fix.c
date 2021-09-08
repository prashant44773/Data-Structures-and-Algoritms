#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int Top;
    char *arr;
};

int isEmpty(struct Stack *p)
{
    if (p->Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *p)
{
    if (p->Top == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char Pop(struct Stack *p)
{
    if (isEmpty(p) == 1)
    {
        printf("\nStack UnderFlow ! Cannot Pop Elements\n");
    }
    else
    {
        char ch;

        ch = p->arr[p->Top];

        p->Top--;

        return ch;
    }
}

char Push(struct Stack *p, char ch)
{
    if (isFull(p) == 1)
    {
        printf("Stack OverFlow ! Cannot Push %c", ch);
    }
    else
    {
        p->Top++;

        p->arr[p->Top] = ch;
    }
}

char stackTop(struct Stack *p)
{
    char c;

    c = p->arr[p->Top];

    return c;
}

int isOperator(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-')
    {
        return 0;
    }
}

int Precedence(char h)
{
    if (h == '*' || h == '/')
    {
        return 3;
    }
    else if (h == '-' || h == '+')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

char *Infix_to_Postfix(char *infix)
{
    struct Stack *str;
    str = (struct Stack *)malloc(sizeof(struct Stack));
    str->Top = -1;
    str->size = 100;

    str->arr = (char *)malloc(str->size * sizeof(char));

    char *Postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isOperator(infix[i]) == 0)
        {
            if (Precedence(infix[i]) > Precedence(stackTop(str)))
            {
                Push(str, infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = Pop(str);
                j++;
            }
        }
        else
        {
            Postfix[j] = infix[i];
            i++;
            j++;
        }
    }

    while(isEmpty(str) != 1)
    {
        Postfix[j] = Pop(str);

        j++;
    }

    Postfix[j] = '\0';

    return Postfix;

}

int main()
{
    char *exp = "a-b+t/6";

    printf("The Postfix is  :   %s",Infix_to_Postfix(exp));

    return 0;
}