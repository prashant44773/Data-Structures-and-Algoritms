#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// struct node *front = NULL, *back = NULL;  //

void display(struct node *h)
{
    printf("\n");

    while (h != NULL)
    {
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL");

    printf("\n");
}

struct node *createNode(int var)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = var;
    head->next = NULL;

    return head;
}

int getheight(struct node *h)
{
    int count = 0;

    while (h != NULL)
    {
        h = h->next;
        count++;
    }

    return count;
}

void splitList(struct node *head, struct node **front, struct node **back)
{
    int height, rounds = 0;
    height = getheight(head); // printf("The height of head is : %d\n",height);

    struct node *current = head;

    for (int i = 0; i < (height / 2); i++)
    {
        rounds++;
        current = current->next;
    } // printf("The Value of Rounds is :  %d",rounds);

    *front = head;
    *back = current->next;

    current->next = NULL;
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth, *sixth, *seventh, *eight;

    head = createNode(34);
    second = createNode(79);
    third = createNode(89);
    fourth = createNode(44);
    fifth = createNode(31);
    sixth = createNode(59);
    seventh = createNode(37);
    eight = createNode(44);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    display(head);

    struct node *front = NULL, *back = NULL;
    front = (struct node *)malloc(sizeof(struct node));
    back = (struct node *)malloc(sizeof(struct node));

    splitList(head, &front, &back);

    printf("\nFront List");
    display(front);

    printf("\nBack List");
    display(back);

    return 0;
}