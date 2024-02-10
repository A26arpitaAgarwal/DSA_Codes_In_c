// Insertion in linked list
// Case III - Insertion in the end, O(n)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node insertAtEnd(struct node *first, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
}

int main()
{
    struct node *first;
    struct node *second;
    struct node *third;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    first->data = 30;
    first->next = second;

    second->data = 23;
    second->next = third;

    third->data = 8;
    third->next = NULL;

    linkedListTraversal(first);
    insertAtEnd(first, 26);
    printf("\nNew Linked List is ---> \n");
    linkedListTraversal(first);
    return 0;
}