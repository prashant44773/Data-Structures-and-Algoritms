#include<stdio.h>
#include<stdlib.h>


struct queue 
{
    int size;
    int f;
    int r;

    int *arr;
};


int isEmpty(struct queue *q)
{
    if(q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int isFull(struct queue *q)
{
    if(q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int enqueue(struct queue *q,int val)
{
    if(isFull(q) == 1)
    {
        printf("\nThe Queue is Full \n");
    }
    else
    {
        q->r++;

        q->arr[q->r] = val;

    }
}



int dequeue(struct queue *q)
{
    if(isEmpty(q) == 1)
    {
        printf("\nThe Queue is Empty \n");
    }
    else
    {
        q->f++;

        return q->arr[q->f];
    }
}




int main()
{
    struct queue str;

    str.size = 50;

    str.f = str.r = -1;

    str.arr = (int *)malloc(str.size*sizeof(int));


    printf("The value of isEmpty function is :  %d\n",isEmpty(&str));
    printf("The value of isFull function is :  %d\n",isFull(&str));
    
    printf("\nPushed Three elements to the queue\n");
    enqueue(&str,34);
    enqueue(&str,56);
    enqueue(&str,25);

    printf("The value of isEmpty function is :  %d\n",isEmpty(&str));
    printf("The value of isFull function is :  %d\n",isFull(&str));

    printf("\ndequeue some elements to the queue\n");

    int e;

    e = dequeue(&str);

    printf("\nThe dequeue element from the queue is  :  %d\n",e);

    printf("The value of isEmpty function is :  %d\n",isEmpty(&str));
    printf("The value of isFull function is :  %d\n",isFull(&str));


    

    return 0 ;
}