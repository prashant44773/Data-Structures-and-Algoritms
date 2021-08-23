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

//................Operations on Linklist...............//
/*
     1. Insertion on the Head (at 1 Position)
     2. Inseertion at the End (1 step Befor NULL)
     3. Inserrtion in Between (at any Index)
     4. Insertion After Node (Adding a New Node)  
*/

// 1. Insertion on the Head (at 1 Position)

struct Node *Insertion_Head(struct Node *head, int add)
{
    struct Node *ptr;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->Next = head;
    ptr->data = add;

    return ptr;
}

// 2. Inseertion at the End (1 step Befor NULL)

struct Node *Insert_End(struct Node *head, int add)
{
    struct Node *ptr, *str = head;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    while (str->Next != NULL)
    {
        str = str->Next;
    }

    ptr->data = add;
    str->Next = ptr;
    ptr->Next = NULL;

    return head;
}

// 3. Inserrtion in Between (at any Index)

struct Node *Insert_Index(struct Node *head, int add, int index)
{
    struct Node *ptr, *str = head;

    // struct Node *str = head ;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    int i = 0;

    while (i != index - 1)
    {
        str = str->Next;

        i++;
    }

    ptr->data = add;
    ptr->Next = str->Next;
    str->Next = ptr;

    return head;
}


// 4. Insertion After Node (Adding a New Node)  

struct Node *Insert_Extention(struct Node *head , struct Node *prevNode , int add )
{
    // struct Node *prevNode  // here prevNode represents a Node like (head , second , Third , Fourth)

    struct Node *ptr ;

    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = add ;

    ptr->Next = prevNode->Next ;
    prevNode->Next = ptr;

    return head;
}




int main()
{
    struct Node *head, *second, *third, *fourth; // *Newhead;

    // Allocating Memory in Heap for Linklist

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    // Newhead = (struct Node *)malloc(sizeof(struct Node));

    // creating Linklist

    head->data = 4;
    head->Next = second;

    second->data = 6;
    second->Next = third;

    third->data = 8;
    third->Next = fourth;

    fourth->data = 10;
    fourth->Next = NULL;

    //..............................................//

    int element, index;
    printf("\nEnter the Element to be Insrted : \t");
    scanf("%d", &element);

    printf("\nEnter the Index at which Element to be Insrted : \t");
    scanf("%d", &index);

    printf("\n\n");

    printf("The Linklist is : \n");

    Traversal(head);

    // // Newhead = Insertion_Head(head,element);  //As the function returns New Head we are assigning it to old Head
    // head = Insertion_Head(head,element);  //As the function returns New Head we are assigning it to old Head

    // head = Insertion_Head(head,element); 
    // head = Insertion_Head(head,555);
    // head = Insertion_Head(head,444);


    // head = Insert_Index(head,element,index);  // Insertion in between

    // Insertion at the end

    // head = Insert_End(head, element);  // Insertion at the End

    // head = Insert_Extention(head , head , element);
    
    printf("\nThe Modidfied Linklist is :  ");

    // Traversal(Newhead);
    Traversal(head);

    return 0;
}