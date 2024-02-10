// Deleting the element from in between in the linked list
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

struct node *deleteInBetween(struct node *head, int index)
{
    // Two pointers will traverse to reach the element
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
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
    head = deleteInBetween(head, 1);
    printf("\nLinked List after deletion:-- \n");
    linkedList_traversal(head);

    return 0;
}