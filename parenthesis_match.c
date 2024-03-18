// Parenthesis matching using arrays in c language

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

void push(struct stack *p, char val)
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
        char val = p->arr[p->top + 1];
        p->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialise the stack
    struct stack *sp;
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "8*((9))())";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}