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

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void Insertion(struct node *root, int key)
{
    struct node *prev = NULL;

    if (root == NULL)
    {
        printf("The BST is Empty\n");
        return;
    }

    while (root != NULL)
    {
        prev = root;

        if (root->data == key)
        {
            printf("The Element is Already Present in BST\n");
            return;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    struct node *new = createNode(key);

    if (prev->data < key)
    {
        prev->right = new;
        printf("Key Inserted\n");
    }
    else
    {
        prev->left = new;
        printf("Key Inserted\n");
    }
}

int main()
{
    struct node *p, *p1, *p2, *p3, *p4;
    p = createNode(9);
    p1 = createNode(7);
    p2 = createNode(12);
    p3 = createNode(6);
    p4 = createNode(8);

    /*         9
             /   \
            7     12
           / \
          6   8
    */

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    inOrderTraversal(p);
    printf("\n");

    Insertion(p, 5);
    printf("\n");

    inOrderTraversal(p);

    return 0;
}
