#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    Node():data(0),left(NULL),right(NULL){}
    Node(int d):data(d),left(NULL),right(NULL){}

};

void insert(Node* &root,int data){
    if(root ==NULL){
        root = new Node(data);
        return;
    }
    if(data<root->data){
        insert(root->left,data);
    }
    else{
        insert(root->right,data);
    }

}

void print(const Node*root){
    if(root==NULL){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);

}

void levelOrderPrint(Node*root){

queue<Node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){

Node*out = q.front();
q.pop();

if(out==NULL){
    if(!q.empty()){
        q.push(NULL);
    }
    cout<<endl;
}
else{
    cout<<out->data<<" ";


    if(out->left){
        q.push(out->left);
    }
    if(out->right){
        q.push(out->right);
    }
}
}

return ;
}

int main(){

Node*root = NULL;
insert(root,5);
insert(root,1);
insert(root,6);
insert(root,8);
insert(root,2);
insert(root,0);

print(root);
cout<<endl;
levelOrderPrint(root);
return 0;
}
