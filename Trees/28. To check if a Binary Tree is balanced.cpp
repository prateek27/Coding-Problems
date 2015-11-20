#include<iostream>
#include<queue>
using namespace std;

/* Problem create a BST from Array . BST should have minimal height */
/* Author : Prateek Narang */


struct node{
int data;
node*left,*right;
    node(int data){
        this->data = data;
        left=NULL;
        right = NULL;
    }
};

int getHeight(struct node*root);

bool isBalanced(struct node*root){
//Approach 1: Calculate height at every node
if(getHeight(root)==-1)
    return false;
else
    return true;
}

//returns -1 if a imbalance occurs at any level
int getHeight(struct node*root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = getHeight(root->left);
    if(leftHeight==-1){
        return -1;
    }
    int rightHeight = getHeight(root->right);
    if(rightHeight==-1){
        return -1;
    }

    int heightDiff = abs(rightHeight-leftHeight);
    if(heightDiff>1){
        return -1;
    }
    else{
        return max(leftHeight,rightHeight)+1;
    }

}

void print(struct node*root){
    //Use Level order Traversal to print the tree.
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);

        }
        else{
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
            }
       }
    }
}

void printPostorder(struct node*root){
if(root){
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
    }
}

int main(){
//int a[10]={1,2,3,4,5};
//struct node*tree = makeTree(a,0,4);
//print(tree);
node*root1=new node(5);
root1->left  = new node(7);
root1->left->left = new node(8);
root1->left->left->left=new node(9);
root1->right = new node(6);
//root1->right->left = new node(3);
print(root1);
if(isBalanced(root1))
    cout<<"Yes it is Balanced !";
else
    cout<<"Not Balanced";

return 0;
}

