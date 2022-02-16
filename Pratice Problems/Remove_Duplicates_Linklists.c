#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Traversal(struct node *h)
{
    while (h != NULL)
    {
        printf("%d->", h->data);
        h = h->next;
    }
    printf("NULL\n");
}

struct node *createNode(int var)
{
    struct node *h;
    h = (struct node *)malloc(sizeof(struct node));
    h->data = var;
    h->next = NULL;
    return h;
}

void sortLinklist(struct node *ptr)
{
    struct node *current, *Next;

    current = ptr;

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
}

// void RemoveDuplicates(struct node *h)  // My Approach
// // struct node *RemoveDuplicates(struct node *h)
// {
//     // printf("Removing Duplicates\n");
//     struct node *current, *Next;
//     current = h;

//     while (current != NULL)
//     {
//         Next = current->next;
//         while (Next != NULL)
//         {
//             if (current->data == Next->data)
//             {
//                 struct node *del;
//                 del = Next;
//                 Next = Next->next;
//                 current->next = Next;

//                 free(del);
//             }
//             Next = Next->next;
//         }

//         current = current->next;
//     }

//     printf("Removing Duplicates\n");
//     // return h;
// }

// void RemoveDuplicates(struct node *h) // Internet's Method
// {
//     printf("Removing Duplicates\n");
//     struct node *current;
//     current = h;

//     while (current->next != NULL)
//     {
//         if (current->data != current->next->data)
//         {
//             current = current->next;
//         }
//         else
//         {
//             struct node *nexNext = current->next->next;
//             free(current->next);
//             current->next = nexNext;
//         }
//     }
// }

void RemoveDuplicates(struct node *current) // MY Own Trial  to solve this through recursion ! It Works....Wow !
{
    // printf("Removing Duplicates\n");

    if (current->next == NULL)
    {
        return;
    }

    if (current->data != current->next->data)
    {
        current = current->next;

        RemoveDuplicates(current);
    }
    else
    {
        struct node *nexNext = current->next->next;
        free(current->next);
        current->next = nexNext;

        RemoveDuplicates(current);
    }
    // printf("End of function");
}

int main()
{
    struct node *head, *second, *third, *fourth, *fifth, *sixth, *seventh, *eighth , *nineth;

    head = createNode(12);
    second = createNode(12);
    third = createNode(20);
    fourth = createNode(44);
    fifth = createNode(34);
    sixth = createNode(44);
    seventh = createNode(44);
    eighth = createNode(200);
    nineth = createNode(12);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = nineth;

    Traversal(head);
    sortLinklist(head);
    // head = RemoveDuplicates(head);
    RemoveDuplicates(head);
    Traversal(head);

    return 0;
}