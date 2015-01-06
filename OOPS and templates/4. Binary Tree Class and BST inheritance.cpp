#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
int data;

Node*left;
Node*right;
public:
    Node(int d){
    this->data = d;
    this->left = NULL; this->right=NULL;
    }
    int getData(){
    return data;
    }

    Node*getLeft(){
    return left;
    }

    Node*getRight(){
    return right;
    }

    Node*setData(int data){
    this->data = data;
    }
    Node*setRight(Node*r){
    right = r;
    }
    Node*setLeft(Node*l){
    left = l;
    }
};

class BinaryTree{

protected:
    Node*root;

public:

    BinaryTree(){
     root=NULL;
    }
    void insert(int data){
    //Inserting in a level order
    if(root==NULL){
        root = new Node(data);
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node*temp = q.front();
        q.pop();
        if(temp->getLeft()==NULL)
            {
                temp->setLeft(new Node(data));
                return ;
            }
        else if(temp->getRight()==NULL){
            temp->setRight(new Node(data));
            return ;
        }
        q.push(temp->getLeft());
        q.push(temp->getRight());
        }

    }
    void printInorder(){
    if(root==NULL)
    return;

    struct Node*temp=root;
    root=root->left;
    this->printInorder();
    root = temp;
    cout<<root->data<<" ";
    root = root->right;
    this->printInorder();
    root = temp;

    }



};

class BST:public BinaryTree{

public:
     static Node*insertRecursively(Node*root,int data);

public:
void insert(int data){
insertRecursively(root,data);
    }
};

  Node* BST::insertRecursively(Node*root,int data){
    if(root==NULL){
        return new Node(data);
    }
    else if(root->getData()>data){
        return insertRecursively(root->getLeft(),data);
    }
    else{
        return insertRecursively(root->getRight(),data);
    }
};

int main(){
BinaryTree bt;
bt.insert(1);
bt.insert(5);
bt.insert(3);
bt.insert(4);
bt.insert(2);
bt.insert(7);
bt.insert(6);
cout<<"Binary Tree Formed: ";
bt.printInorder();
cout<<endl;

BST bst ;
bst.insert(1);
bst.insert(5);
bst.insert(3);
bst.insert(4);
bst.insert(2);
bst.insert(7);
bst.insert(6);
cout<<"BST FORMED : ";
bst.printInorder();
cout<<endl;

return 0;
}
