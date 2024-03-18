// Implementing insertion in binary search tree using linked representation

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void Insertion(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already exist in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createNode(2);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

int main()
{
    int key = 2;

    struct node *p = createNode(22);
    struct node *p1 = createNode(12);
    struct node *p2 = createNode(34);
    struct node *p3 = createNode(8);
    struct node *p4 = createNode(15);
    struct node *p5 = createNode(32);
    struct node *p6 = createNode(49);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;
    p2->right = p6;

    Insertion(p, key);
    printf("%d", (p3->left)->data);

    return 0;
}