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
        return 1;
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
        return 1;
    }
    else
    {
        return 0;
    }
}

int Match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 0;
    }
    else if (a == '[' && b == ']')
    {
        return 0;
    }
    else if (a == '{' && b == '}')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

char Push(struct Stack *ptr, char ch)
{
    if (isFull(ptr) == 1)
    {
        printf("\nStack OverFlow ! Cannot Push  %c\n", ch);
    }
    else
    {
        ptr->Top++;

        ptr->arr[ptr->Top] = ch;
    }
}

char Pop(struct Stack *ptr)
{
    if (isEmpty(ptr) == 1)
    {
        printf("\nStack UnderFlow ! Cannot Pop Anymore\n");
    }
    else
    {
        char ch;

        ch = ptr->arr[ptr->Top];

        ptr->Top--;

        return ch;
    }
}

int  Match_Multiplle_Paraenthesis(char *exp)
{
    char Popped;

    struct Stack *str;

    str->size = 20;

    str->Top = -1;

    str->arr = (char *)malloc(str->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            Push(str, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(str) == 1)
            {
                return 1;
            }

            Popped = Pop(str);

            if (Match(Popped, exp[i]) != 0)
            {
                return 1;
            }
        }
    }

    if (isEmpty(str) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char *exp = "{3+4*[34-3 (3*20) - 34)]-90-12}";

    int var;

    var = Match_Multiplle_Paraenthesis(exp);
    

    if (var == 0)
    {
        printf("\nParanthesis Matched\n");
    }
    else
    {
        printf("\nParanthesis Does Not Matched\n");
    }

    return 0;
}