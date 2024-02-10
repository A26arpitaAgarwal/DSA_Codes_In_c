// Stack operations such as push(), pop(), peek(), stackTop, and stackBottom--> TC for everything is O(1)
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// Time complexity of isEmpty and isFull is O(1)
int isEmpty(struct stack *p)
{
    if (p->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *p)
{
    if (p->top == p->size - 1)
        return 1;
    else
        return 0;
}

// we are not using size anywhere so TC is O(1)
void push(struct stack *p, int val)
{
    if (isFull(p))
    {
        printf("Stack is overflow! Cannot push the value %d\n", val);
    }
    else
    {
        p->top++;
        p->arr[p->top] = val;
    }
}

int pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack underflow! Cannot pop the element\n");
        return -1;
    }
    else
    {
        int val = p->arr[p->top + 1];
        p->top--;
        return val;
    }
}

int peek(struct stack *s, int i)
{
    if (s->top - i + 2 < 0)
    {
        printf("Invalid value for the position.");
        return -1;
    }
    else
    {
        return s->arr[s->top - i + 2];
    }
}

int main()
{
    int val, limit;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));

    printf("Enter the values you wanted to insert: ");
    scanf("%d", &limit);
    printf("Enter the value to be inserted: ");
    for (int i = 1; i <= limit; i++)
    {
        scanf("%d", &val);
        push(s, val);
    }

    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    pop(s);
    printf("Popped %d from the stack\n", pop(s));

    printf("Top : %d\n", s->top + 2); // TOP+2 bcz top is starting from -1

    // For printing the values from stack
    for (int j = 1; j <= s->top + 2; j++)
    {
        printf("The value at idex %d is %d\n", j, peek(s, j));
    }

    // Time complexity of stackTop and stackBottom is O(1)
    printf("Top of the stack is: %d\n", s->arr[s->top]);
    printf("Bottom of the stack is : %d\n", s->arr[0]);

    return 0;
}