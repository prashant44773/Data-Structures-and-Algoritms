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

    } while (p != NULL);

    printf("\nThe Double Linklist in Revesed Direction is : \t");

    while (q != NULL)
    {
        printf("%d ", q->data);

        q = q->prev;
    }
}

// 1. Insertion at any index

struct Node *Insert_Index(struct Node *h, int ind, int value)
{
    struct Node *a, *b, *c, *d, *add;

    add = (struct Node *)malloc(sizeof(struct Node));

    add->data = value;

    a = h;

    b = h->next;

    int i = 0;

    while (i != ind - 2)
    {
        i++;

        a = a->next;

        b = b->next;
    }

    c = a;

    // Pointing the next pointer to add  and  from add to next
    a->next = add;
    a = a->next;
    add->next = b;

    // Pointing the previous pointer to add Node.....//

    b->prev = add;
    b = b->prev;
    add->prev = c;

    return h;
}

// 2. Insertion at the Head

struct Node *Insert_Head(struct Node *h, int value)
{
    struct Node *add, *p;

    add = (struct Node *)malloc(sizeof(struct Node));

    add->data = value;

    p = h;

    add->next = p;

    p->prev = add;

    add->prev = NULL;

    return add;
}

// 3. Insertion at the END

struct Node *Insert_End(struct Node *h, int value)
{
    struct Node *p, *add;

    p = h;

    add = (struct Node *)malloc(sizeof(struct Node));
    add->data = value;

    while (p->next != NULL)
    {

        p = p->next;
    }

    p->next = add;
    add->next = NULL;

    add->prev = p;

    return h;
}

// 4. Deletion at the head

struct Node *Delete_Head(struct Node *h)
{
    struct Node *p, *q;

    p = h;

    q = h->next;

    q->prev = NULL;

    free(p);

    return q;
}

// 5 . Deletion at the End
struct Node *Delete_End(struct Node *h)
{
    struct Node *p, *q;

    p = h;

    q = h->next;

    while (q->next != NULL)
    {
        p = p->next;

        q = q->next;
    }

    p->next = NULL;

    free(q);
}

// 6. Deletion at Given Index or Node

struct Node *Delete_Index(struct Node *h, int ind)
{
    struct Node *p, *q, *o;

    p = h;

    q = h->next;

    int i = 0;

    while (i != ind)
    {
        o = p;

        p = p->next;

        q = q->next;

        i++;
    }


    o->next = q;  // pointing Node o  To  Node q

    q->prev = o;

    free(p);

    return h;
 
}

int main()
{
    struct Node *head, *second, *third, *fourth, *fifth , *sixth , *seventh , *eigth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));
    seventh = (struct Node *)malloc(sizeof(struct Node));
    eigth = (struct Node *)malloc(sizeof(struct Node));

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
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->data = 25;
    sixth->next = seventh;

    seventh->prev = sixth;
    seventh->data = 32;
    seventh->next = eigth;

    eigth->prev = seventh;
    eigth->data = 37;
    eigth->next = NULL;

    printf("The Linklist is : \t");

    Traversal(head);

    printf("\n\nThe Updated Linklist is : \n");

    // head = Insert_Index(head,5,55);

    // head = Insert_Head(head , 44);

    // head = Insert_End(head,99);

    // head = Delete_Head(head);

    // head = Delete_End(head);

    // head = Delete_Index(head, 5);

    Traversal(head);

    return 0;
}