#include<stdio.h>
#include<stdlib.h>


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


int isBST(struct node *root)
{
    static struct node *prev = NULL;

    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }

        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);

    }
    else
    {
        return 1;
    }
}


struct node *Search(struct node *root , int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return Search(root->left,key);
    }
    else
    {
        return Search(root->right,key);
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

    struct node *n = Search(p,7);

    if(n != NULL)
    {
        printf("Found :  %d\n",n->data);
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;

}
