#include<iostream>
#include<cstdio>
using namespace std;



struct node{
int data;
struct node*left;
struct node*right;
};

struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->left=node->right=NULL;
return node;
};

void boundaryTrav(struct node*node)
{

    if(node->left==NULL&node->right==NULL)
       { printf("%d ",node->data); return ;}

        boundaryTrav(node->left);
        boundaryTrav(node->right);

}

int main(){

 struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);

    boundaryTrav()
return 0;
}

