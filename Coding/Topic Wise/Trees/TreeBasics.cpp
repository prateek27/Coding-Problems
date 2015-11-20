#include<iostream>
using namespace std;

//Defines tree structure ,inserts a node , prints it .
struct node{
int data;
struct node*left;
struct node*right;
};

struct node*newNode(int data){
struct node*node = new struct node;
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
};

struct node*insert(struct node*node,int data)
{
    if(node==NULL)
        return newNode(data);

    else{
        if(data<=node->data) node->left=insert(node->left,data);
        else node->right=insert(node->right,data);
        return node;
        }
}

void print(struct node*node){

if(node==NULL)
    return;
else{
    print(node->left);
    cout<<node->data;
    print(node->right);

}
}



int main(){

struct node*root = newNode(5);
insert(root,6);
insert(root,1);
insert(root,3);
insert(root,0);
print(root);

return 0;
}
