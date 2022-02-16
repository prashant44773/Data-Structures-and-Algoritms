#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;

    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
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
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(struct queue *q, int val)
{
    if (isFull(q) == 1)
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
    if (isEmpty(q) == 1)
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
    // Intializing the queue

    struct queue q;

    q.size = 50;

    q.f = q.r = -1;

    q.arr = (int *)malloc(q.size * sizeof(int));

    //........Implementing the BFS.........//

    int u;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int a[7][7] = {

        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    printf("%d ",i);
    visited[i] = 1;

    enqueue(&q,i);  // enqueue i for Exploration

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);

        for(int j=0 ; j < 7 ; j++)
        {
            if(a[node][j] == 1  &&  visited[j] == 0)
            {
                printf("%d ",j);
                visited[j] = 1;
                enqueue(&q,j);  
            }
        }
    }
    


    return 0;
}