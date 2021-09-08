#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *Next;
};


// struct Node *Top = NULL;  // Declaring Top as Global Variable




//..........Traversal of Stack(Linklist).............//

void Traversal(struct Node *s)
{
    while (s != NULL)
    {
        printf("%d\n", s->data);

        s = s->Next;
    }
}

int isEmpty(struct Node *p)
{
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *ptr)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));

    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *Push(struct Node *top, int value)
{
    int status;

    status = isFull(top);
    if (status == 1)
    {
        printf("\nStack OverFlow ! Cannnot Push Value %d \n", value);
    }
    else
    {
        struct Node *ptr;

        ptr = (struct Node *)malloc(sizeof(struct Node));

        ptr->data = value;

        ptr->Next = top;

        top = ptr;

        return top;
    }
}

int Pop(struct Node **top)  // giving this Function address of Stack so the changes made in this should be Applied to the Top variable in Main Function too
{
    int status ;

    status = isEmpty(*top);
    if(status == 1)
    {
        printf("\nStack UnderFlow ! Cannot Pop Anymore Elements !\n");
    }
    else
    {
        int x;
        struct Node *ptr;

        ptr = *top;

        x = ptr->data;

        *top = ptr->Next;

        free(ptr);

        return x;
    }
}


// Implementing Pop using Global Variable


// int Pop(struct Node *p) //  Implementing top as Global Variable
// {
//     int status;

//     status = isEmpty(p);
//     if (status == 1)
//     {
//         printf("\nStack UnderFlow ! Cannot Pop Anymore Elements !\n");
//     }
//     else
//     {
//         int x;
//         struct Node *ptr;

//         ptr = p;

//         x = ptr->data;

//         Top = ptr->Next;

//         free(ptr);

//         return x;
//     }
// }


// Peek function :

int Peek(struct Node *tp ,  int position)
{
    struct Node *p = tp ;
    for (int i = 0 ;(i < position-1 && p != NULL); i++)
    {
        p = p->Next;

    }


    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        printf("\nInvalid Position ! No Such Position Exist in the Stack\n");
        return -1;
    }
}




int Stack_Top(struct Node *tp)
{
    return tp->data ;
}



int Stack_Bottom(struct Node *tp)
{
    struct Node *q ;

    q = tp;

    while(q->Next != NULL)
    {
        q = q->Next;
    }

    return q->data;
}



int main()
{
    int check;

    struct Node *Top ;

    Top = NULL;

    check = isFull(Top);
    printf("The Value of Top Stack is  %d\n", check);

    check = isEmpty(Top);
    printf("The Value of Top Stack is  %d\n", check);

    Top = Push(Top, 44);
    Top = Push(Top, 58);
    Top = Push(Top, 33);
    Top = Push(Top, 29);
    Top = Push(Top, 10);

    printf("\nThe Traversal of Stack Before Popping is :  \n");

    Traversal(Top);

    // int element;

    // element = Pop(&Top); // Implementing top as Pointer and Address

    // element = Pop(Top); // Implementing top as Global Variable
    // element = Pop(Top); // Implementing top as Global Variable
    // element = Pop(Top); // Implementing top as Global Variable

    // printf("\nThe Element that we have Popped is :  %d\n", element);

    // printf("\nThe Traversal of Stack is :  \n");

    // Traversal(Top);

    // int pos;

    // pos = 3;

    // printf("The element at Position %d  is  :  %d",pos,Peek(Top,pos));


    // printf("The Value at Stack_Top is :  %d\n",Stack_Top(Top));
    printf("The Value at Stack_Bottom is :  %d\n",Stack_Bottom(Top));

    return 0;
}