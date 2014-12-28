#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
struct node*next;  //Next will point to inorder successor
};

//---------------------------------------Build Level Order
struct node*build(){
struct node*root = new node;
cout<<"Enter Root's Data";
cin>>root->data;

queue<node*> q;
q.push(root);

while(!q.empty()){

    struct node*temp = q.front();
    q.pop();
    cout<<"Enter the children (or -1) for node with data as "<<temp->data<<" : ";
    int data1;
    int data2;
    cin>>data1>>data2;

    if(data1!=-1){
          temp->left  = new node;
          temp->left->data = data1;
          temp->left->next = NULL;
         q.push(temp->left);
    }
    else{
    temp->left = NULL;
    }

    if(data2!=-1){
        temp->right = new node;
        temp->right->data = data2;
        temp->right->next = NULL;
        q.push(temp->right);
    }
    else{
    temp->right = NULL;
    }
  }
return root;
}
//--------------------------------------------------Print Level Order
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
//---------------------------------------------------Set Next pointers
void setNextPointers(struct node*root){
    if(root==NULL)
    {
     return;
    }
    struct node*temp = root ;


    if(root->left!=NULL){
    root->left->next = root;
    }
    setNextPointers(root->left);

    if(root->right!=NULL){
    root->right->next = root->next;
    root->next = root->right;
    }
    setNextPointers(root->right);
}

//---------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
if(node->next!=NULL)
    cout<<node->data<<" -> "<<node->next->data<<endl;
else
    cout<<node->data<<" -> NULL ";
printInorder(node->right);

}

void printInorderUsingNextPointers(struct node*root){
    while(root!=NULL)
    {
        cout<<root->data<<" ";
        root = root->next;

    }
}

int main(){
struct node*root1 = build();
root1->next = NULL;
setNextPointers(root1);

cout<<"Inorder Recursive with  next fields :"<<endl;
printInorder(root1);
cout<<endl<<"Inorder Using Next Pointers (Efficient):"<<endl;
printInorderUsingNextPointers(root1); // Not it will start from root and it will print only the next larger elements
cout<<endl;
}
