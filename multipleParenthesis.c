// Multiple Parenthesis matching such as '(', '[', '{ ' using arrays in c language
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
        char val = p->arr[p->top];
        p->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialise the stack
    struct stack *sp;
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char pop_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop_ch = pop(sp);
            if (!match(pop_ch, exp[i]))
            {
                return 0;
            }
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
    char *exp = "{[[2-7]]+(22)}[*]{{12*74}}";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching and balanced\n");
    }
    else
    {
        printf("The parenthesis is not matching and unbalanced\n");
    }
    return 0;
}