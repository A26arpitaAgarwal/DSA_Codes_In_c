// Insertion in circular linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedList_traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertionAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
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
    third->next = head;

    linkedList_traversal(head);
    head = insertionAtFirst(head, 65);
    printf("\nThe new circular linked list is : \n");
    linkedList_traversal(head);

    return 0;
}