#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
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
         q.push(temp->left);
    }
    else{
    temp->left = NULL;
    }

    if(data2!=-1){
        temp->right = new node;
        temp->right->data = data2;
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
//---------------------------------------------------Are Identical
bool areIdentical(struct node*root1,struct node*root2){

if(root1==NULL&&root2==NULL)
    return true;

else if(root1!=NULL&&root2==NULL || root1==NULL&&root2!=NULL)
    return false;

else if(root1->data==root2->data&&areIdentical(root1->left,root2->left)&&areIdentical(root1->right,root2->right))
    return true;

return false;
}

//---------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
cout<<node->data<<" ";
printInorder(node->right);

}


int main(){
struct node*root1 = build();
struct node*root2 = build();
cout<<"Level Order :"<<endl;
cout<<endl<<"Tree 1"<<endl;
printLevelOrder(root1);
cout<<endl<<"Tree 2"<<endl;
printLevelOrder(root2);
if(areIdentical(root1,root2))
    cout<<"Identical Trees";
else
    cout<<"Not Identical Trees ";
cout<<endl;
}
