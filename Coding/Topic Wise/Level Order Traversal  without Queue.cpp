#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node{
int data;
struct node*left,*right;
};



struct node*newNode(int data)
{
    struct node*node=new struct node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


void printGivenLevel(struct node*node,int level){
if(node==NULL)
    return;
if(level==1)
    cout<<node->data<<" ";
else{
    printGivenLevel(node->left,level-1);
    printGivenLevel(node->right,level-1);
    }
}
int maxHeight(struct node*node){
if(node==NULL)
    return 0;
else
    return (max(maxHeight(node->left),maxHeight(node->right)))+1;
}


void printNodeLevel(struct node*root)
{
    int height= maxHeight(root);
        int i;
        for(i=1;i<=height;i++)
                   {

                    printGivenLevel(root,i);
                    cout<<endl;
                   }
return;
}

int main(){

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Level order traversal is "<<endl;
    printNodeLevel(root);
    return 0;
}
