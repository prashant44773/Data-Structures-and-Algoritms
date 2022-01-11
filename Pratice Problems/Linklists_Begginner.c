#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *h)
{
    while (h != NULL)
    {
        printf("%d ", h->data);

        h = h->next;
    }
}

struct node *Insertion_Tail(struct node *p,int var)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));

    struct node *t = p;


    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->data = var;
    p->next = ptr;
    ptr->next = NULL;

    return t; 
}

int main()
{
    struct node *first, *second, *third, *fourth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;
    
    display(first);
    first = Insertion_Tail(first,85);
    first = Insertion_Tail(first,95);
    first = Insertion_Tail(first,105);
    first = Insertion_Tail(first,115);
    first = Insertion_Tail(first,125);
    printf("\nInsertion at Tail...\n");
    display(first);

    return 0;
}