#include <stdio.h>
#include<stdlib.h>


struct Node
{
    int data;

    struct Node *Next;
};

void Traversal(struct Node *p)
{
    struct Node *q = p->Next;

    do
    {
        printf("%d ", p->data);

        p = p->Next;

    } while (p->Next != q);
}

// 1. Addding Node or Value at Head in Circular Linklist

struct Node *Insert_Head(struct Node *head, int value)
{
    struct Node *add, *e, *r;

    e = head;

    r = head;

    add = (struct Node *)malloc(sizeof(struct Node));

    add->data = value;

    while (head->Next != e)
    {

        head = head->Next;
    }

    head->Next = add;

    add->Next = e;

    return add;
}


// 2. Addding Node or Value at Any given Index in Circular Linklist

struct Node *Insert_Index(struct Node *head, int var, int ind)
{
    struct Node *w, *str, *t;

    str = (struct Node *)malloc(sizeof(struct Node));

    str->data = var;

    w = head;
    t = head;

    t = t->Next;

    int i = 0;

    while (i != ind - 1)
    {
        printf("%d ", w->data);

        w = w->Next;

        t = t->Next;

        i++;
    }

    w->Next = str;

    str->Next = t;

    return head;
}


// 3. Add Node or Value at the End / Extend the Linklist

struct Node *Insert_Extend(struct Node *head , int value)
{
    struct  Node *add , *p , *a;

    add = (struct Node *)malloc(sizeof(struct Node));

    add->data = value;

    p = head;

    a = head->Next;

    do
    {
        p = p->Next;

        a = a->Next;

    }while(p->Next != head);

    p->Next = add;

    add->Next = a;

    return head;



}

int main()
{
    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->Next = second;

    second->data = 7;
    second->Next = third;

    third->data = 11;
    third->Next = fourth;

    fourth->data = 17;
    fourth->Next = fifth;

    fifth->data = 22;
    fifth->Next = head;

    int var = 100, ind = 3;

    printf("The Circular Linklist is : \n");
    Traversal(head);

    printf("\n\n\n");

    // head = Insert_Head(head, 44);

    // head = Insert_Index(head, var, 5);

    head = Insert_Extend(head,500);
    head = Insert_Extend(head,600);
    head = Insert_Extend(head,700);
    head = Insert_Extend(head,800);

    printf("\nThe Modified Circular Limklist is : \t");

    Traversal(head);

    return 0;
}