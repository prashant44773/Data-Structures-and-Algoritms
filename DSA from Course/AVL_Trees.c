#include <stdio.h>
#include <stdlib.h>



int max(int a , int b)
{
    return a > b ? a : b;
}


struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int var)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = var;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;

    return new;
}

void inOrderTraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return n->height;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return getHeight(n->left) - getHeight(n->right);
}

struct node *RightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node *LeftRotate(struct node *x)
{
    struct node *y = x->left;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct node *Insertion(struct node *root, int key)
{
    if (root == NULL)
    {
        return (createNode(key));
    }

    if (key > root->data)
    {
        root->right = Insertion(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = Insertion(root->left, key);
    }

    return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // left left case
    if (bf > 1 && key < root->left->data)
    {
        RightRotate(root);
    }

    // right right case
    if (bf < -1 && key > root->right->data)
    {
        LeftRotate(root);
    }

    // left right case
    if (bf > 1 && key > root->left->data)
    {
        root->left = LeftRotate(root->left);
        RightRotate(root);
    } 

    // right left case
    if (bf < -1 && key < root->right->data)
    {
        root->right = RightRotate(root->right);
        LeftRotate(root);
    }

    return root;

};

int main()
{
    // struct node *p, *p1, *p2, *p3, *p4;
    // p = createNode(9);
    // p1 = createNode(7);
    // p2 = createNode(12);
    // p3 = createNode(6);
    // p4 = createNode(8);

    // /*         9
    //          /   \
    //         7     12
    //        / \
    //       6   8
    // */

    // p->left = p1;
    // p->right = p2;

    // p1->left = p3;
    // p1->right = p4;

    // inOrderTraversal(p);

    struct node *root = NULL;

    root = Insertion(root,1);
    root = Insertion(root,3);
    root = Insertion(root,7);
    root = Insertion(root,6);
    root = Insertion(root,5);
    root = Insertion(root,4);
    root = Insertion(root,2);

    inOrderTraversal(root);


    return 0;
}