#include<iostream>
#include<queue>
using namespace std;
// Approach BFS Traversal
//----------------------------------Node Structure
struct node{
int data;
struct node*left;
struct node*right;
};
//----------------------------------------New Node function
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
};
//------------------------------------------------Insert a node
struct node*insert(struct node*node,int data)
{
    if(node==NULL){

        node=newNode(data);
        return node;
    }
    else{
            if(data<=node->data)
            node->left=insert(node->left,data);

            else
                node->right=insert(node->right,data);
        }

};
//-----------------------------------------------Find the next right node/print null if no node exists
struct node* nextRightNode(struct node*node,int key){

queue<int> qlevel;
queue<struct node*> qaddress;

qaddress.push(node);
qlevel.push(0);      //Level of root node

while(qaddress.size()){

    int level=qlevel.front();
    struct node*node=qaddress.front();

    qaddress.pop();
    qlevel.pop();

    if(node->data==key)
        {
        if(qlevel.size()==0||qlevel.front()!=level)
            return NULL;

        return qaddress.front();
        }
    if(node->left!=NULL)
    {
        qaddress.push(node->left);
        qlevel.push(level+1);
    }
    if(node->right!=NULL)
    {
        qaddress.push(node->right);
        qlevel.push(level+1);
    }

}

}

//----------------------------------------------------Print inorder Traversal
void print(struct node*node){
    if(node==NULL) return;

print(node->left);
cout<<node->data;
print(node->right);
}
//-----------------------------------------------------Main Function
void test(node *root, int k)
{
    node *nr = nextRightNode(root, k);
    if (nr != NULL)
      cout << "Next Right of " << k << " is " << nr->data << endl;
    else
      cout << "No next right node found for " << k << endl;
}

// Driver program to test above functions
int main()
{
    // Let us create binary tree given in the above example
    node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);

    test(root, 10);
    test(root, 2);
    test(root, 6);
    test(root, 5);
    test(root, 8);
    test(root, 4);
    return 0;
}
