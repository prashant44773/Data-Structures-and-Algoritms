#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int f;
    int r;
    int a; // for stroing f intial position
    int x; // for storing r intial position
    int *arr;
};

void PrintComplete(struct DEQueue *s)
{
    int val;
    val = s->f;

    s->f = 0;

    while(s->f != s->size-1)
    {
        printf("%d ",s->arr[s->f]);

        s->f++;
    }

    s->f = val;
}


void PrintQueue(struct DEQueue *t)
{
    int num;

    num = t->f; // Storing the Value of Front Pointer....

    int i = 0;

    // printf("\nThe Double Ended Queue From the Front is :\t");

    while (i != num + 1)
    {
        printf("%d ", t->arr[i]);

        i++;
    }

    t->f = num;

    int var, j = t->size - 2;

    var = t->r;

    // printf("\nThe Double Ended Queue From the Rear is :\t");

    while (j != var-1)
    {
        printf("%d ", t->arr[j]);

        j--;
    }

    t->r = var;
}

int isFull_Front(struct DEQueue *a)
{
    if (a->f == a->r)
    {
        // printf("\nQueue Ended\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty_Front(struct DEQueue *a)
{
    if (a->f == -1)
    {
        // printf("\nQueue is EmptY\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull_Rear(struct DEQueue *a)
{
    if (a->r == a->f)
    {
        // printf("\nQueue Ended\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty_Rear(struct DEQueue *a)
{
    if (a->r == a->size - 1)
    {
        // printf("\nQueue is EmptY\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//....................................................................//

//....................................................................//

int EnqueueFrom_Rear(struct DEQueue *q, int val)
{

    if (isFull_Rear(q) == 1)
    {
        printf("\nThe Queue is Full from Rear Side\n");
    }
    else
    {
        q->r--;
        q->arr[q->r] = val;
    }
}

int DequeueFrom_Rear(struct DEQueue *q)
{

    if (isEmpty_Rear(q) == 1)
    {
        printf("\nThe Queue is Empty from Rear Side\n");
    }
    else
    {
        int var;

        var = q->arr[q->r];

        q->r++;

        return var;
    }
}

int DEqueueFrom_Front(struct DEQueue *q)
{

    if (isEmpty_Front(q) == 1)
    {
        printf("\nThe Queue is Empty from Front Side\n");
    }
    else
    {
        int val;

        q->a++;
        
        val = q->arr[q->a] ; //q->arr[q->f];

        // q->f--;

        return val;
    }
}

int EnqueueFrom_Front(struct DEQueue *q, int val)
{

    if (isFull_Front(q) == 1)
    {
        printf("\nThe Queue is Full from Front Side\n");
    }
    else
    {
        q->f++;

        q->arr[q->f] = val;
    }
}

int main()
{
    struct DEQueue str;

    str.size = 10;

    str.f = str.a = -1;

    str.r = str.x = str.size - 1;

    str.arr = (int *)malloc(sizeof(int) * str.size);

    EnqueueFrom_Front(&str, 45);
    EnqueueFrom_Front(&str, 78);
    EnqueueFrom_Front(&str, 20);
    EnqueueFrom_Front(&str, 100);

    EnqueueFrom_Rear(&str, 22);
    EnqueueFrom_Rear(&str, 69);
    EnqueueFrom_Rear(&str, 77);
    EnqueueFrom_Rear(&str, 39);
    EnqueueFrom_Rear(&str, 99);

    EnqueueFrom_Front(&str, 122);

    // printf("\nThe Elements in Double Ended queue are : \t");
    // PrintComplete(&str);

    PrintQueue(&str);

    // printf("\nThe Dequeue Element from the Front is  %d\n", DEqueueFrom_Front(&str));
    
    printf("\nThe Dequeue Element from the Rear is  %d\n",DequeueFrom_Rear(&str));
    printf("\nThe Dequeue Element from the Rear is  %d\n",DequeueFrom_Rear(&str));
    printf("\nThe Dequeue Element from the Rear is  %d\n",DequeueFrom_Rear(&str));

    // PrintQueue(&str);
    PrintComplete(&str);

    printf("\n\n");

    EnqueueFrom_Front(&str, 10);
    EnqueueFrom_Front(&str, 30);
    EnqueueFrom_Front(&str, 70);
    
    PrintQueue(&str);

    return 0;
}