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

    // inOrderTraversal(p);  // if inOrder Traversal Prints Values in Ascending order then the Tree is Binary Tree...// 
    
    printf("The Value of isBST is : %d\n",isBST(p));
    
    return 0;

}
