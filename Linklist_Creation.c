#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *Next;
};

void linklist_Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is : %d\n", ptr->data);

        ptr = ptr->Next;
    }
}

int main()
{
    //.........Declaring pointers for dynamic Memory allocation..............//

    struct Node *head, *second, *third, *fourth, *fifth;

    //...........................Allocate Memeory in Heap for Linklist........................//

    head = (struct Node *)malloc(sizeof(struct Node));

    second = (struct Node *)malloc(sizeof(struct Node));

    third = (struct Node *)malloc(sizeof(struct Node));

    fourth = (struct Node *)malloc(sizeof(struct Node));

    fifth = (struct Node *)malloc(sizeof(struct Node));

    //.................Assigning Value to Link list Head.............//

    // link first and second with next pointer

    head->data = 1;
    head->Next = second;

    // link second and third with next pointer

    second->data = 2;
    second->Next = third;

    // link third and fourth with next pointer

    third->data = 3;
    third->Next = fourth;

    // link fouth and fifth with next pointer

    fourth->data = 4;
    fourth->Next = fifth;

    // link fifth and NULL with next pointer

    fifth->data = 5;
    fifth->Next = NULL;

    linklist_Traversal(head);

    return 0;
}