#include<iostream>
#include<cstdio>
using namespace std;
//-----------------------------------AVL node structure
struct node{
int data;
struct node*right;
struct node*left;
int height;
};
//-------------------------------------------------GetHeight
int height(struct node*N)
{
    if(N==NULL) return 0;
    return N->height;
}
//---------------------------------------------Left Rotate
struct node*rightRotate(struct node*y)
{
    struct node*x=y->left;
    struct node*T2=x->right;

    x->right=y;
    y->left=T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

return x;
};
//----------------------------------------------Right Rotate
struct node*leftRotate(struct node*x){
    struct node*y=x->right;
    struct node*T2=y->left;

    y->left=x;
    x->right=T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
};

//-------------------------------------------------newNode
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->right=NULL;
node->left=NULL;
node->height=1;
return node;
};
//-------------------------------------------------GetBalance
int getBalance(struct node*node)
{
    return height(node->left)-height(node->right);
}
//----------------------------------------------------KMax
int max(int a,int b) { return a>b?a:b;}

//-----------------------------------------------------Insert
struct node*insert(struct node*node,int data){

if(node==NULL)
    return newNode(data);

if(data<node->data)
    node->left=insert(node->left,data);
else
    node->right=insert(node->right,data);

node->height=max(height(node->left),height(node->right))+1;
int balance = getBalance(node);

   if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data> node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}
//--------------------------------------------------------Main
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Drier program to test above function*/
int main()
{
  struct node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);

  return 0;
}
