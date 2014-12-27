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

void printInorder(struct node*root){
if(root==NULL)
    return ;

printInorder(root->left);
cout<<root->data<<" ";
printInorder(root->right);
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

//------------------------------------------------Find Inorder Pred
struct node*findPred(struct node*root){
    if(root==NULL||root->left==NULL)
        return NULL;

    node*output = root->left;
    while(output->right!=NULL){
        output = output->right;
    }

    return output;
}

//------------------------------------------Delete a Node with Given Data



struct node* removeNode(struct node*root , int data ){

    if(root==NULL)
        return NULL;
    if(root->data > data){
        root->left = removeNode(root->left,data);
        return root;
    }
    else if(root->data < data){
        root->right = removeNode(root->right,data);
        return root;
    }
    else{  //Data is Equal to key
    // 3 Cases

        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL){
            struct node*temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            struct node*temp = root->left;
            delete root;
            return temp;

        }
        else{ //Dangerous Case : TWO CHILDREN , Find  Precdecessor
            struct node*toBeDeleted = findPred(root);
            root->data = toBeDeleted->data;
            root->left = removeNode(root->left,toBeDeleted->data);
            return root;
        }
    }
}



int main(){
int a[8]={1,2,3,4,5,6,7,9};
struct node*root = NULL;
root = createBST(a,0,7);

insert(root,8);
insert(root,13);
//insert(root,4);
cout<<"Originial "<<endl;

printLevelOrder(root);
cout<<endl<<"Inorder : "<<endl;
printInorder(root);
cout<<endl<<"After removing 4 and 7..."<<endl;
removeNode(root,4);
removeNode(root,7);
cout<<endl;
printInorder(root);
return 0;
}

