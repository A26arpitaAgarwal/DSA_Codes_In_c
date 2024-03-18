// Implementing binary search tree using linked representation

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

int isBST(struct node *root)
{
    static struct node *pre = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (pre != NULL && root->data <= pre->data)
        {
            return 0;
        }
        pre = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
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

    inOrder(p); // If inorder is in ascending order then it will be always a BST
    printf("\n");
    if (isBST(p) == 1)
    {
        printf("It is a BST");
    }
    else
    {
        printf("It is not a BST");
    }
    return 0;
}