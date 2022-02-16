#include<stdio.h>


struct node
{
    int data;
    struct node *next;
};



void display(struct node *h)
{
    while (h != NULL)
    {
        printf("%d->",h->data);
        h = h->next;
    }
    printf("NULL");
}


int main()
{
    struct node five = {50,NULL};
    struct node fourth = {40,&five};
    struct node third = {30,&fourth};
    struct node second = {20,&third};
    struct node first = {10,&second};

    struct node *head = &first;

    display(head); 



    return 0;
}