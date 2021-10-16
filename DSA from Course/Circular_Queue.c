#include<stdio.h>
#include<stdlib.h>


struct Queue 
{
    int size;
    int f;
    int r;
    int *arr;
};


int isFull(struct Queue *q)
{
    if((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int isEmpty(struct Queue *q)
{
    if(q->r == q->f)
    {
        printf("\nCircular Queue is Empty\n");
        return 1;
    }
    else
    {
        return 0;
    }
}




int enqueue(struct Queue *p,int w)
{
    if(isFull(p) == 1)
    {
        printf("\nCircular Queue is Full\n");
    }
    else
    {
        p->r = (p->r + 1) % p->size;

        p->arr[p->r] = w;
    }
}



int dequeue(struct Queue *q)
{
    if(isEmpty(q) == 1)
    {
        printf("\nCircular Queue is Empty\n");
    }
    else
    {
        q->f++;

        return q->arr[q->f];
    }

}





int main()
{
    struct Queue st;

    st.size = 5;
    st.f = st.r = 0;
    
    st.arr = (int *)malloc(st.size*sizeof(int));
    
    enqueue(&st,34);
    enqueue(&st,56);
    enqueue(&st,88);
    enqueue(&st,47);
    // enqueue(&st,92);

    dequeue(&st);
    dequeue(&st);
    dequeue(&st);
    dequeue(&st);
    dequeue(&st);


    // int val , val1;

    // val = isEmpty(&st);

    // printf("\nThe value of isEmpty is  %d\n",val);

    // val1 = isFull(&st);

    // printf("\nThe value of isFull is  %d\n",val1);

    return 0 ;
}