// Implementing circular queue using array
#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % (q->size) == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct CircularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full.\n");
    }
    else
    {
        printf("Enqueued element: %d\n", val);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct CircularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty.\n");
    }
    else
    {
        q->f = (q->r + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct CircularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // enqueue some elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 11);

    // dequeue elements
    printf("Dequeue the element %d.\n", dequeue(&q));
    printf("Dequeue the element %d.\n", dequeue(&q));
    printf("Dequeue the element %d.\n", dequeue(&q));

    enqueue(&q, 13);

    if (isEmpty(&q))
    {
        printf("Queue is empty.\n");
    }
    if (isFull(&q))
    {
        printf("Queue is full.\n");
    }

    return 0;
}