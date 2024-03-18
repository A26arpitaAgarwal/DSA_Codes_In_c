// Conversion of infix to postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *p)
{
    return p->arr[p->top];
}

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

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *infixToPostfix(char *infix)
{
    // stack to resolve the operators position
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // character array for postfix
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // traversal for the infix
    int j = 0; // traversal to postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))

            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s\n", infixToPostfix(infix));
    return 0;
}