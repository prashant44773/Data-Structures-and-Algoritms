#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *next;
    struct Node *prev;
};

struct Node *Traversal(struct Node *head)
{
    struct Node *p, *q;

    p = head;

    printf("\nThe Double Linklist in Forward Direction is : \t");

    do
    {
        q = p;

        printf("%d ", p->data);
        p = p->next;

    }while (p != NULL);

    printf("\nThe Double Linklist in Revesed Direction is : \t");

    while(q != NULL)
    {
        printf("%d ",q->data);

        q = q->prev;
    }
    
}


int main()
{
    struct Node *head, *second, *third, *fourth, *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->prev = NULL;
    head->data = 3;
    head->next = second;

    second->prev = head;
    second->data = 7;
    second->next = third;

    third->prev = second;
    third->data = 11;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 17;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 22;
    fifth->next = NULL;

    printf("The Linklist is : \t");

    Traversal(head);

    printf("\n\nThe Updated Linklist is : \n"); 

    Traversal(head);
    return 0;
}