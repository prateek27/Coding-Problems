#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};

void printLevelOrder(node*root){

queue<node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    node*temp = q.front();
    q.pop();

    if(q.empty())
        {
        cout<<endl;
        break;
        }

    else if(temp==NULL)
    {
        q.push(NULL);
        cout<<endl;
    }
    else{
        cout<<temp->data<<" ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
            }
        }
    }
}

//----------------------------------------------------Create from Array
struct node*createBST(int *a,int low,int high){

if(low==high)
    {
    struct node*leaf = new node;
    leaf->data = a[low];
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
    }
else if(low<high){
    struct node*root = new node;
    int mid = (low+high)/2;
    root->data = a[mid];
    root->left = createBST(a,low,mid-1);
    root->right = createBST(a,mid+1,high);

    return root;
    }
return NULL;
}

void printPreorder(struct node*root){
if(root==NULL)
    return ;

printPreorder(root->left);
cout<<root->data<<" ";
printPreorder(root->right);
}

//----------------------------------------------Insert a node
struct node* insert(struct node*root,int data){
if(root==NULL){
    struct node*insertedNode = new node;
    insertedNode->data = data;
    insertedNode->left = insertedNode->right = NULL;
    return insertedNode;
}
if(data< root->data)
    root->left = insert(root->left,data);
else
   root->right = insert(root->right,data);
return root;
}
//---------------------------------------------Next Bigger Node / Inorder Successor in BST
struct node*findMin(struct node*root){
    while(root->left!=NULL)
        root = root->left;
    return root;
}

//Iteratively ...
struct node*nextBiggerNode(struct node*root,struct node*n){

//Case 1.
if(n->right!=NULL){
    return findMin(n->right);
}
//Case 2.
struct node*required = NULL;
    while(root!=NULL){
        if(n->data<root->data){
            required = root;
            root = root->left;

        }
        else if(n->data>root->data){
            root = root->right;
        }
        else{
            return required;
        }

    }

}
int main(){
int a[8]={1,2,3,4,5,6,7,9};
struct node*root = NULL;
root = createBST(a,0,7);
cout<<"Originial "<<endl;
printLevelOrder(root);
insert(root,8);
cout<<endl<<"After inserting 8 "<<endl;

printLevelOrder(root);
cout<<endl<<"Inorder : "<<endl;
printPreorder(root);

cout<<endl<<"Inorder sucessor of "<<root->left->left->data<<" is "<<nextBiggerNode(root,root->left->left)->data;

return 0;
}
