#include<iostream>
#include<queue>
using namespace std;

struct Node{
int data;
Node **children;
int childcount;
};

//-------------------------------------------------------Build Recursively
void buildRecursively(struct Node**root){

    if(*root == NULL){
        cout<<"Enter Node's data ";
        *root = new Node;
        cin>>(*root)->data;
        cout<<"Enter Number of Children of Node with data as "<<(*root)->data<<" : ";
        cin>>(*root)->childcount;

        if((*root)->childcount==0)
                return;
        (*root)->children = new Node*[(*root)->childcount];
        for(int i=0;i<(*root)->childcount;i++){
            (*root)->children[i]=NULL;
            buildRecursively(&(*root)->children[i]);
            }

    }

}
//------------------------------------------------------Print Tree Preorder
//Inorder traversal is not possible , if there fixed no of nodes say 4 . Then we can print 2 left and 2 right
void printTreePreorder(Node *root)
{
    if(root==NULL){
    return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->childcount;i++){
        printTreePreorder(root->children[i]);
    }
}
//--------------------------------------------------Print Tree PostOrder
void printTreePostOrder(Node*root){
    if(root==NULL)
    {
    return ;
    }
    for(int i=0;i<root->childcount;i++){
        printTreePostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
//--------------------------------------Find Max in Tree
Node* findMax(Node *root){
    if(root==NULL){
        return NULL;
    }

    Node*largest = root;

    for(int i=0;i<root->childcount;i++){
    Node*temp=findMax(root->children[i]);
        if(temp->data > largest->data)
        {
        largest = temp;
        }
    }
return largest;
}
//------------------------------------------Find Depth in Tree
int findDepth(Node *root){

if(root==NULL){
    return 0;
}

int depth = -1;
for(int i=0;i<root->childcount;i++){
depth = max(depth,findDepth(root->children[i]));
}
return depth+1;
}

//-----------------------------------------Print Level Order
void printLevelOrder(Node*root){

queue<Node*> q;
q.push(root);
q.push(NULL);

while(!q.empty()){
    Node*temp = q.front();
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
        cout<<temp->data<<", ";
        for(int i=0;i<temp->childcount;i++){
            q.push(temp->children[i]);
            }
        }
    }
}
//-----------------------------------------------Main
int main(){
struct Node*root = NULL;
buildRecursively(&root);
cout<<"Level Order :"<<endl;
printLevelOrder(root);
cout<<"Preorder "<<endl;
printTreePreorder(root);
cout<<endl;
cout<<"Postorder "<<endl;
printTreePostOrder(root);
cout<<endl;
cout<<"Max Element :"<<findMax(root)->data<<endl;
cout<<"Depth : "<<findDepth(root);
return 0;
}

