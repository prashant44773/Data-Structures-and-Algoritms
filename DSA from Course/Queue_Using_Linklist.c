#include <stdio.h>
#include <stdlib.h>


struct Queue *f = NULL;
struct Queue *r = NULL;





struct Queue
{
    int data;

    struct Queue *next;
};

void Traversal(struct Queue *ptr)
{
    printf("The  Traversaled linklist  is  :  \n");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);

        ptr = ptr->next;

    }
}


int Enqueue(int val)
{
    struct Queue *n = (struct Queue *)malloc(sizeof(struct Queue));

    if(n == NULL)
    {
        printf("\nQueue is Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;

        if(f == NULL)
        {
            f=r=n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }

}



int Dequeue()
{
    int val = -1;

    struct Queue *ptr = f;

    if(f==NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        
    }

    return val ;
}




int main()
{

    
    Enqueue(33);
    Enqueue(56);
    Enqueue(25);
    Enqueue(45);
    Enqueue(78);

    // Traversal(f);

    printf("\nThe dequeued Element is :  %d\n",Dequeue());
    printf("\nThe dequeued Element is :  %d\n",Dequeue());
    printf("\nThe dequeued Element is :  %d\n",Dequeue());

    Traversal(f);

    return 0;
}