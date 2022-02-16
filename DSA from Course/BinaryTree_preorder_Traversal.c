#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int var)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = var;
    head->left = NULL;
    head->right = NULL;
    return head;
}

void preOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{
    struct node *p, *p1, *p2, *p3, *p4;
    p = createNode(45);
    p1 = createNode(20);
    p2 = createNode(34);
    p3 = createNode(13);
    p4 = createNode(7);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    preOrderTraversal(p);
    printf("\n");
    postOrderTraversal(p);
    printf("\n");
    inOrderTraversal(p);
    return 0;
}
