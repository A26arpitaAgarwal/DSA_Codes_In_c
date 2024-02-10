// Implementing stack using arrays in c language

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.");
}

int isFull(struct stack *p, int size)
{
    if (p->top == p->size - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.");
}

int main()
{
    // struct stack S;
    // S.size = 10;
    // S.top = -1;
    // S.arr = (int *)malloc(S.size * sizeof(int));
    // return 0;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    isEmpty(s);
    isFull(s, s->size);
    return 0;
}