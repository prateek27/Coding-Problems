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

//---------------------------------------------------Print Inorder
void printInorder(struct node*node){
if(node==NULL)
    return;
printInorder(node->left);
cout<<node->data<<" ";
printInorder(node->right);

}
//--------------------------------------------------Find Largest BST
struct thing{
struct node* largest;
int count;
int Min,Max;
};

struct thing findLargestBST(struct node*root){
struct thing output;
if(root==NULL){
    output.Min  = 10000;
    output.Max =  -10000;
    output.count = 0;
    output.largest =NULL;
    return output;
}

struct thing out1 = findLargestBST(root->left);
struct thing out2 = findLargestBST(root->right);

if( root->data > out1.Max && root->data < out2.Min && root->left == out1.largest && root->right == out2.largest )
{
    output.count = out1.count + out2.count+1;
    cout<<output.count<<" ";
    output.largest = root;
    output.Min = out1.Min;
    output.Max = out2.Max;
    return output;
}
else{
    if(out1.count > out2.count)
    {
    return out1;
    }
    else
    {
    return out2;
        }

    }
}










int main(){
struct node*root = build();
cout<<"Level Order :"<<endl;
printLevelOrder(root);
cout<<"Inorder : "<<endl;
printInorder(root);
cout<<endl<<"Largest BST Starts from :";
cout<<findLargestBST(root).largest->data<<endl;
return 0;
}



