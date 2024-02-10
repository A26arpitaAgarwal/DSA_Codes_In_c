// Insertion in linked list
// Case I - Insertion in the beginning , O(1)

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedList_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *First(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    // Allocating the memory to nodes in the heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Allocating the data to nodes and linking of first and second node
    head->data = 7;
    head->next = second;

    // Linking second and third node
    second->data = 34;
    second->next = third;

    // Pointing to null pointer
    third->data = 4;
    third->next = NULL;

    linkedList_traversal(head);
    head = First(head, 31);
    printf("\nNew linked list --> \n");
    linkedList_traversal(head);

    return 0;
}