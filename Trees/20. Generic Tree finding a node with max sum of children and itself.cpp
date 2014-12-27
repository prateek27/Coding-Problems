#include<iostream>
#include<queue>
using namespace std;

struct Node{
int data;
Node **children;
int childcount;
};

//------------------------------------------------------Build Tree using Level Order Traversal
Node *buildTree(){
Node *root = new Node;
cout<<"Enter data for root node"<<endl;
cin>>root->data;
// Level Order Building of Tree , So Use A Queue
queue<Node *> Q;

Q.push(root);

while(!Q.empty()){
    Node *temp = Q.front();
    Q.pop();
    cout<<" Enter child count of node with data as "<<temp->data<<endl;
    cin>>temp->childcount;
    temp->children = new Node*[temp->childcount];

    for(int i=0;i<temp->childcount;i++){
    temp->children[i] = new Node;
    cout<<"Enter data for child "<<i<<" : ";
    cin>>temp->children[i]->data;
    Q.push(temp->children[i]);
        }

    }
return root;
}

//--------------------------------------Find Max in Tree
struct thing{
int sum;
struct Node* maxNode;
};

thing findMaxSum(Node *root){

    struct thing output;

    if(root==NULL){
        output.sum = 0;
        output.maxNode = NULL;
        return output;
    }

    output.maxNode = root;
    output.sum = root->data;
    for(int i=0;i<root->childcount;i++){
        output.sum += root->children[i]->data;
    }

    for(int i=0;i<root->childcount;i++){

    thing output2 = findMaxSum(root->children[i]);
        if(output2.sum > output.sum)
        {
        output.sum = output2.sum;
        output.maxNode = output2.maxNode;
        }
    }
return output;
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
struct Node*root = buildTree();
printLevelOrder(root);
thing result = findMaxSum(root);
cout<<"Node with max children sum and itself is "<<result.maxNode->data<<" and sum is "<<result.sum<<endl;

return 0;
}

