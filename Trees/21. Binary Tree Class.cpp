#include<iostream>
#include<queue>
using namespace std;

struct node{
int data;
struct node*left;
struct node*right;
};



class BinaryTree{
struct node*root;

public:
    BinaryTree(){ root = NULL ; }
    void buildLevelOrder();
    void printInorder();
    void printPostorder();
    void printPreorder();
    void printLevelOrder();
    int getHeight();
    node* findElement(int key);

};

//---------------------------------------Build Level Order
void BinaryTree::buildLevelOrder(){
root = new node;
cout<<"Enter Root's Data : ";
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
}
//--------------------------------------------------Print Level Order
void BinaryTree::printLevelOrder(){

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
void BinaryTree::printInorder(){
if(root==NULL)
    return;


struct node*temp=root;
root=root->left;
this->printInorder();
root = temp;
cout<<root->data<<" ";
root = root->right;
this->printInorder();
root = temp;
}

void BinaryTree::printPostorder(){
if(root==NULL)
    return;


struct node*temp=root;

root=root->left;
this->printPostorder();
root = temp;

root = root->right;
this->printPostorder();
root = temp;

cout<<root->data<<" ";
}
void BinaryTree::printPreorder(){
if(root==NULL)
    return;



struct node*temp=root;
cout<<root->data<<" ";
root=root->left;
this->printPreorder();
root = temp;

root = root->right;
this->printPreorder();
root = temp;

}

int BinaryTree::getHeight(){
    if(root==NULL)
        return 0;

    struct node*temp = root;
    int left , right ;

    root = root->left;
    left = getHeight();
    root = temp;

    root = root->right;
    right = getHeight();
    root = temp;

    return max(left,right)+1;

}

struct node*BinaryTree::findElement(int key){
if(root==NULL)
    return NULL;

struct node*result = NULL;

struct node*temp = root;
root=root->left;

if(this->findElement(key)!=NULL)
    { return root ; }
root = temp;


if(key==root->data)
    return root;


root = root->right;
if(this->findElement(key)!=NULL){
    return root;
}
root = temp;

return result;
}



//----------------------------------Main
int main(){
BinaryTree t;

t.buildLevelOrder();

cout<<endl<<"Level Order : "<<endl;
t.printLevelOrder();
cout<<endl<<"Inorder : "<<endl;
t.printInorder();
cout<<endl<<"Preorder :"<<endl;
t.printPreorder();
cout<<endl<<"Postorder :"<<endl;
t.printPostorder();
cout<<endl<<"Height :"<<t.getHeight()<<endl;
cout<<endl<<"Enter key to search : ";
int key;
cin>>key;
node* result = t.findElement(key);
if(result!=NULL){
cout<<endl<<"Found..."<<result->data<<" with Child Nodes as -  ";
if(result->left!=NULL)
    cout<<result->left->data<<",";
if(result->right!=NULL)
    cout<<result->right->data;
}
return 0;
}

