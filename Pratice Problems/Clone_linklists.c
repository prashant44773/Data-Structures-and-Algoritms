#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *h)
{
    while (h != NULL)
    {
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}

struct node *clone_linklists(struct node *h)
{
    int count = 0; // count the number of elements
    struct node *p = h;
    struct node *t = h;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    // printf("The value of count is : %d\n",count);
    // printf("The value of t->data is : %d\n",t->data);

    int i , var = 50;
    struct node *newnode[50];

    for (i = 0; i < count; i++)
    {
        newnode[i] = (struct node *)malloc(sizeof(struct node));

        newnode[i]->data = t->data;
        newnode[i]->next = t->next;
        t->next++;
    }
    // printf("%d",i);
    newnode[i-1]->next = NULL;

    return newnode[0];
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth, *five ,*clone;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    five = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = five;
    five->data = 50;
    five->next = NULL;

    traversal(head);
    
    clone = clone_linklists(head);
    traversal(clone);

    return 0;
}