#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};


void Traversal(struct node*h)
{
    while(h != NULL)
    {
        printf("%d->",h->data);
        h = h->next;
    }
    printf("NULL\n");
}

struct node *deleting_linklist(struct node*h , int ind)
{
    struct node *p;
    struct node *s;
    
    p = h;
    s = h->next;

    int i=0;
    while(i != ind && s->next != NULL)
    {
        p = p->next;
        s = s->next;
        i++;
    }
    p->next = s->next;
    free(s);

    return h;
}



int main()
{
    struct node *head, *second, *third, *fourth, *fifth, *five ,*clone ,*six,*seven;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    five = (struct node *)malloc(sizeof(struct node));
    six = (struct node *)malloc(sizeof(struct node));
    seven = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = five;
    five->data = 50;
    five->next = six;
    six->data = 60;
    six->next = seven;
    seven->data = 70;
    seven->next = NULL;

    Traversal(head);
    clone =  deleting_linklist(head,3);
    Traversal(clone);

    return 0;
}