#include<iostream>
using namespace std ;

/* Author Prateek Narang 
Self Approach , Work GOOD ! :D
*/
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
//--------------------------------------------------Find Max Sum


struct output{
    node*head;
    node*tail;
};


output BSTtoDLL(struct node*&root){
output ans;

if(root->left==NULL&&root->right==NULL){
            ans.head = root;
            ans.tail = root;
            return ans;
}
if(root->left ==NULL && root->right!=NULL){
    output right = BSTtoDLL(root->right);
    ans.head = root ;
    root->right = right.head;
    right.head->left = root;
    ans.tail = right.tail;
    return ans;
}
if(root->left!=NULL && root->right ==NULL){
    output left = BSTtoDLL(root->left);
    left.tail->right = root;
    root->left = left.tail;
    ans.tail = root;
    ans.head = left.head;
    return ans;
}
else{
    output left = BSTtoDLL(root->left);
    output right = BSTtoDLL(root->right);

    root->right = right.head;
    right.head->left = root;

    root->left = left.tail;
    left.tail->right = root;

    ans.head = left.head;
    ans.tail = right.tail;
    return ans;
    }
}

void print(struct node*root){
struct node*temp = root;

while(temp->left){
    //cout<<temp->data<<endl;
    temp = temp->left;
}
while(temp){
    cout<<temp->data<<" ";
     temp = temp->right;
    }
return;
}


int main(){
struct node*root = build();
cout<<"Level Order :"<<endl;
//printLevelOrder(root);
//printInorder(root);

BSTtoDLL(root);
print(root);
return 0;
}

