#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr)
{
    struct node *h = ptr;
    while (h != NULL)
    {
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}

struct node *push(struct node *h, int var)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = var;
    newnode->next = h;

    h = newnode;

    return h;
}


struct node *pop(struct node *p)
{
    struct node *str = p;

    printf("The Popped Node is %d\n",str->data);

    p = str->next;

    free(str);
    
    return p;
}



int main()
{
    struct node *head;

    head = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = NULL;

    head = push(head, 20);
    head = push(head, 35);
    head = push(head, 48);
    head = push(head, 57);
    head = push(head, 66);

    traversal(head);

    head = pop(head);
    head = pop(head);
    head = pop(head);

    traversal(head);
    
    return 0;
}