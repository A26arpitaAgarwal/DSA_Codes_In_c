// Deleting the node with a given index or value
// Time complexity = O(n)

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

struct node *deleteAtNode(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next == NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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
    head = deleteAtNode(head, 34);
    printf("\nLinked List after deletion:-- \n");
    linkedList_traversal(head);

    return 0;
}