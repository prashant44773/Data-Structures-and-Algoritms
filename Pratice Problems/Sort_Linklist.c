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
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}


struct node *push(struct node *h,int var)
{
    struct node *head;

    head = (struct node*)malloc(sizeof(struct node));
    
    head->data = var;
    head->next = h;

    return head;
}



struct node *sortlist(struct node *p)
{
    struct node *current = p, *Next = NULL;

    while (current != NULL)
    {
        Next = current->next;
        while (Next != NULL)
        {
            if (current->data > Next->data)
            {
                int temp;

                temp = current->data;
                current->data = Next->data;
                Next->data = temp;
            }

            Next = Next->next;
        }

        current = current->next;
    }

    return p;
}



int main()
{
    // system("cls");

    struct node *head, *second, *third, *fourth, *fifth, *sixth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));
    sixth = (struct node *)malloc(sizeof(struct node));

    head->data = 34;
    head->next = second;

    second->data = 54;
    second->next = third;

    third->data = 56;
    third->next = fourth;

    fourth->data = 73;
    fourth->next = fifth;

    fifth->data = 29;
    fifth->next = sixth;

    sixth->data = 16;
    sixth->next = NULL;

    head = push(head,45);
    head = push(head,84);
    head = push(head,39);

    display(head);
    printf("\nAfter Sorting The Linklist\n\n");
    sortlist(head);
    display(head);

    // int a = 10 , b = 32 ,temp=0;

    // printf("The value of a is :  %d\n",a);
    // printf("The value of b is :  %d\n",b);
    // printf("\nAfter Swapping\n\n");

    // swap(&a,&b);

    // printf("The value of a is :  %d\n",a);
    // printf("The value of b is :  %d\n",b);

    return 0;
}