// Implementing deletion in binary search tree using linked representation

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

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Rightmost element of left sub tree
struct node *inOrderPre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *inPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Searching
    if (value < root->data)
    {
        deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        deleteNode(root->right, value);
    }

    // Deletion
    else
    {
        inPre = inOrderPre(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
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

    deleteNode(p, 8);
    inOrder(p);

    return 0;
}