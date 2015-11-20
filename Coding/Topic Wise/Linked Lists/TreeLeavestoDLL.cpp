#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

struct node*extractLeafList(struct node*root,struct node**head){

if(root==NULL) return NULL;

if(root->left==NULL&&root->right==NULL){
    root->right=*head;

    if(*head!=NULL) (*head)->left=root;
    *head=root;
    return NULL;
}
root->right=extractLeafList(root->right,head);
root->left=extractLeafList(root->left,head);
return root;
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
         printf("%d ",root->data);
         print(root->right);
    }
}

// Utility function for printing double linked list.
void printList(struct node *head)
{
     while (head)
     {
         printf("%d ", head->data);
         head = head->right;
     }
}

// Driver program to test above function
int main()
{
     struct node *head = NULL;
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

     root = extractLeafList(root, &head);

     printf("\nExtracted Double Linked list is:\n");
     printList(head);

     printf("\nInorder traversal of modified tree is:\n");
     print(root);
     return 0;
}
