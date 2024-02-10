// Implementing doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void doubleLLtraverse(struct node *p)
{
    // struct node *p = N1;
    while (p != NULL)
    {
        printf("\nElement: %d", p->data);
        p = p->next;
    }
}

void doubleLLbackwardTraverse(struct node *p)
{
    while (p != NULL)
    {
        printf("\nElement: %d", p->data);
        p = p->prev;
    }
}

int main()
{
    struct node *N1;
    struct node *N2;
    struct node *N3;

    N1 = (struct node *)malloc(sizeof(struct node));
    N2 = (struct node *)malloc(sizeof(struct node));
    N3 = (struct node *)malloc(sizeof(struct node));

    N1->data = 23;
    N1->prev = NULL;
    N1->next = N2;

    N2->data = 26;
    N2->prev = N1;
    N2->next = N3;

    N3->data = 29;
    N3->prev = N2;
    N3->next = NULL;

    printf("\nForward traversal: ");
    doubleLLtraverse(N1);
    printf("\n\nBackward traversal: ");
    doubleLLbackwardTraverse(N3);

    return 0;
}