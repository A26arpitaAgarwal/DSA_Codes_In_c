// Insertion in linked list
// Case II - Insertion in between(need to traverse the pointer) O(n)

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

struct node insertAtindex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head; // p is a traversal to reach the index
    int i = 0;
    while (i != index - 1) // coming one position before, where to insert
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

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

    insertAtindex(head, 56, 1);
    printf("\nNew linked list --> \n");

    linkedList_traversal(head);

    return 0;
}