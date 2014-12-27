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



//----------------------------------------------------Convert a BST into DLL

void BSTtoLL(struct node*root,struct node* &head,struct node* &tail){

if(root==NULL){
    head = NULL;
    tail = NULL;
    return ;
}


struct node*headLeft=NULL;
struct node*tailLeft=NULL;

struct node*headRight=NULL;
struct node*tailRight=NULL;

BSTtoLL(root->left,headLeft,tailLeft);
BSTtoLL(root->right,headRight,tailRight);

if(headLeft==NULL){
head = root;
}
else{
    tailLeft->right =root;
    head = headLeft;
    }
if(headRight==NULL){
    tail = root;
}
else{
    tail = tailRight;
    root->right = headRight;
    }
}

//------------------------------------------------Method 2 : Using a structure to return
struct llpair{
node*head;
node*tail;
};

llpair convertToLL(node *root){
llpair output;

if(root==NULL){
    output.head=NULL;
    output.tail=NULL;
    return output;
}

llpair leftResult = convertToLL(root->left);
llpair rightResult = convertToLL(root->right);

    if(leftResult.head == NULL){
        output.head = root;
    }
    else{
        output.head = leftResult.head;
        leftResult.tail->right = root;
    }
    if(rightResult.head==NULL){
        output.tail = root;
    }
    else{
        output.tail = rightResult.tail;
        root->right = rightResult.head;
    }
    return output;
}

void printLL(struct node*root){
cout<<"linked list : ";


while(root!=NULL){
    cout<<root->data<<"->";
    root=root->right;
    }
return ;
}

//---------------------------------------Main

int main(){
int a[8]={1,2,3,4,5,6,7,8};
struct node*root = NULL;
root = createBST(a,0,7);
struct node*head = NULL;
struct node*tail = NULL;
BSTtoLL(root,head,tail);
printLL(head);
//printLL(convertToLL(root).head);
return 0;
}



