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
 

struct node *inOrderPredeccesor(struct node*root)
{
    root = root->left;

    while (root->right != NULL)
    {
        root = root->right;
    }

    return root;
}



struct node *Deletion(struct node *root , int key)
{
    struct node *iPre;

    if(root == NULL)
    {
        return NULL;
    }

    if(root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }

    if(key < root->data)
    {
        root->left = Deletion(root->left,key);
    }
    else if(key > root->data)
    {
        root->right = Deletion(root->right,key);
    }
    else
    {
        iPre = inOrderPredeccesor(root);
        root->data = iPre->data;
        root->left = Deletion(root->left,iPre->data); 
    } 

    return root;
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

    // inOrderTraversal(p);
    // printf("\n");

    // Insertion(p, 5);
    // printf("\n");

    inOrderTraversal(p); 
    printf("\n");
    Deletion(p,9); 
    printf("\n");
    inOrderTraversal(p);

    return 0;
}
