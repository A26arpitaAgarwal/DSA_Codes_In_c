// Insertion in linked list
// Case IV- Insert after a node (pointer is given so no traverse), O(1)

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

struct node insertAfterNode(struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next; // previous node pointer is given to you
    prevNode->next = ptr;
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
    insertAfterNode(first, 122);
    printf("\nNew Linked List is ---> \n");
    linkedListTraversal(first);
    return 0;
}