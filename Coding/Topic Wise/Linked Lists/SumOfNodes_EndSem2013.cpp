#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

int sumOfNodes(struct node*root){

if(root==NULL) return 0;

int leftSum=sumOfNodes(root->left);
int rightSum=sumOfNodes(root->right);

root->data = root->data+leftSum+rightSum;

return root->data;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Utility function for printing tree in In-Order.
void print(struct node *root)
{
    if (root != NULL)
    {
         print(root->left);
         print(root->right);
         printf("%d ",root->data);

    }
}


// Driver program to test above function
int main()
{

     struct node *root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->right = newNode(6);
     root->left->left->left = newNode(7);
     root->left->left->right = newNode(8);
     root->right->right->left = newNode(9);
     root->right->right->right = newNode(10);

     printf("Inorder Trvaersal of given Tree is:\n");
     print(root);

     sumOfNodes(root);

    // printf("\nExtracted Double Linked list is:\n");
    // printList(head);

     printf("\nInorder traversal of modified tree is:\n");
     print(root);
     return 0;
}
/*      1
     /     \
    2       3
   / \       \
  4   5       6
 / \         / \
7   8       9   10
*/
