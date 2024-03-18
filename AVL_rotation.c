// Rotations of AVL tree such as LL, RR, LR, RL
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;

    return p;
}

int BalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    x->right = T2;
    y->left = x;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct node *insert(struct node *p, int key)
{
    if (p == NULL)
    {
        return (createNode(key));
    }
    if (key < p->key)
    {
        p->left = insert(p->left, key);
    }
    if (key > p->key)
    {
        p->right = insert(p->right, key);
        // return p;
    }
    p->height = 1 + max(getHeight(p->left), getHeight(p->right));
    int bf = BalanceFactor(p);

    // LL Case
    if (bf > 1 && key < p->left->key)
    {
        return rightRotate(p);
    }
    // RR Case
    if (bf < -1 && key > p->right->key)
    {
        return leftRotate(p);
    }
    // RL Case
    if (bf < -1 && key < p->right->key)
    {
        p->right = rightRotate(p->right);
        return leftRotate(p);
    }
    // LR Case
    if (bf > 1 && key > p->left->key)
    {
        p->left = leftRotate(p->left);
        return rightRotate(p);
    }
    return p;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrder(root);
    return 0;
}