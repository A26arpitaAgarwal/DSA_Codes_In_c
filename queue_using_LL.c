// Implementing queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{
    printf("Printing the elements of queue: \n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *f)
{
    if (f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *n)
{
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (isFull(n))
    {
        printf("Queue is full!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (isEmpty(f))
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    if (isEmpty(f))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct node *ptr = f;
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    printf("After enqueue the elements are: \n");
    enqueue(12);
    enqueue(13);
    enqueue(14);
    linkedlistTraversal(f);
    printf("Dequeuing element %d from queue.\n", dequeue());
    printf("After dequeueing : \n");
    linkedlistTraversal(f);
    return 0;
}