#include<iostream>
#include<cstdio>
using namespace std;

int maxLevel=0;

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

void leftView(struct node*node,int level)
{
if(node==NULL)
    return;

if(maxLevel<level)
{   maxLevel=level;
    printf("%d ",node->data);
}

leftView(node->left,level+1);
leftView(node->right,level+1);


}

int main(){

    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root,1);


return 0;
}
