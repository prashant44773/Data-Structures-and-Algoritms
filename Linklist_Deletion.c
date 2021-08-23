#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;

    struct Node *Next;
};

void Traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->Next;
    }
}

// 1. Delete head of an Node

struct Node *Delete_Head(struct Node *h)
{
    struct Node *ptr;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr = h;

    h = h->Next;

    free(ptr);

    return h;
}

// 2. Delete at Index in any given Linklist

struct Node *Delete_Index(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *str = head->Next;

    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->Next;

        str = str->Next;
    }
    ptr->Next = str->Next;
    free(str);

    return head;
}

// 3. Delete the last Element

struct Node *Delete_Last(struct Node *head)
{
    struct Node *ptr, *p;

    p = head->Next;

    ptr = head;

    while (p->Next != NULL)
    {
        ptr = ptr->Next;
        p = p->Next;
    }
    ptr->Next = NULL;

    free(p);

    return head;
}

// 4. Delete From Value or given Value

struct Node *Delete_From_Value(struct Node *head, int value)
{
    struct Node *ptr, *str;

    ptr = head;
    str = head->Next;

    while (str->data != value && str->Next != NULL)
    {
        ptr = ptr->Next;
        str = str->Next;
    }

    if (str->data == value)
    {
        ptr->Next = str->Next;

        free(str);

        return head;
    }
    else
    {
        printf("\nElement Not Found\n");
    }

}

int main()
{

    struct Node *head, *second, *Third, *fourth, *fifth, *sixth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    Third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->Next = second;

    second->data = 3;
    second->Next = Third;

    Third->data = 4;
    Third->Next = fourth;

    fourth->data = 5;
    fourth->Next = fifth;

    fifth->data = 6;
    fifth->Next = sixth;

    sixth->data = 7;
    sixth->Next = NULL;

    int index = 1;

    printf("\nThe Linklist Before Deletion : \n\t\t\t\t");
    Traversal(head);

    printf("\n\nThe Linklist After Deletion : \n\t\t\t\t");
    // head = Delete_Head(head);

    // head = Delete_Index(head, index);

    // head = Delete_Last(head);

    // int value = 3;

    head = Delete_From_Value(head, 3);

    Traversal(head);

    return 0;
}