#include<iostream>
#include<climits>
using namespace std;
//---------------------------------------------------Node Structure
struct node{
int data;
struct node*left;
struct node*right;
};
//----------------------------------------------------Create a new Node
struct node* newNode(int data){
struct node*node = new struct node;
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
};
//----------------------------------------------------Insert a new node

struct node*insert(struct node*node,int data)
{
    if(node==NULL)
        { node=newNode(data);
          return node;
        }

    else{
        if(data<=node->data) node->left=insert(node->left,data);
        else node->right=insert(node->right,data);
        }
}
//-------------------------------------------------------Print a Tree Inorder
void print(struct node*node){

if(node==NULL)
    return;
else{
    print(node->left);
    cout<<node->data;
    print(node->right);

}
}
//---------------------------------------------------------Count Number of nodes
int size(struct node*node){
if(node==NULL)
    return 0;
else return (size(node->left)+1+size(node->right));
}
//-----------------------------------------------------------MaxDepth
int maxDepth(struct node*node){
if(node==NULL) return 0;

int ldepth = maxDepth(node->left);
int rdepth= maxDepth(node->right);

if(ldepth>rdepth) return ldepth+1;
else return rdepth+1;
}
//--------------------------------------------------------------Min Value
int minValue(struct node*node){

while(node->left!=NULL)
{
    node=node->left;
}

return node->data;
}
//-------------------------------------------------------------HasPathSum
bool hasPathSum(struct node*node,int value){

    if(node==NULL)
        return value==0?true:false;
    else{
    int leftSum=value-node->data;
    return hasPathSum(node->left,leftSum)||hasPathSum(node->right,leftSum);
    }


}
//------------------------------------------------------PRINT PATHS
void printArray(int ints[],int len)
{ int i;
    for(i=0;i<len;i++);
    cout<<ints[i];

    cout<<endl;
}

void printPathsRecursion(struct node*node,int path[],int pathLen)
{
    if(node==NULL) return;

    path[pathLen]=node->data;
    cout<<"Item Path"<<node->data;
    pathLen++;

    if(node->left==NULL && node->right==NULL){
        printArray(path,pathLen);
    }
    else{
        printPathsRecursion(node->left,path,pathLen);
        printPathsRecursion(node->right,path,pathLen);
        }
}

void printPaths(struct node*node)
{   int path[1000];
    printPathsRecursion(node,path,0);
}
//----------------------------------------------------Mirror (Swap nodes)
struct node* mirror(struct node*node){
if(node==NULL)
    return NULL;
mirror(node->left);
mirror(node->right);

struct node*temp=node->left;
node->left=node->right;
node->right=temp;
};
//------------------------------------------------------Count Trees
int countTrees(int numKeys){
    if(numKeys<=1)
        return 1;

    else{
        int sum=0;
        int i=1;
        for(i=1;i<=numKeys;i++){
        int left=countTrees(i-1);
        int right=countTrees(numKeys-i);
        sum+=left*right;
    }
    return sum;
    }
}
int maxValue(struct node*node){

while(node->right!=NULL){
    node=node->right;
    }
return node->data;
}
//------------------------------------------------------IsBST ?
bool isBST(struct node*node){
if(node==NULL) return true;
if(node->left!=NULL&&minValue(node->left)>node->data)
return false;
if(node->right!=NULL&&maxValue(node->right)<node->data)
    return false;
if(!isBST(node->left)||!isBST(node->right))
    return false;
return true;
}
//----------------------------------------------------IsBSTefficennt Version
bool isBST2Util(struct node*node,int min,int max)
{ if(node==NULL)
    return true;

    if(node->data<min||node->data>max) return false;

    return (isBST2Util(node->left,min,node->data)&&isBST2Util(node->right,node->data+1,max));
}
bool isBST2(struct node*node){
return isBST2Util(node,INT_MIN,INT_MAX);
}
//------------------------------------------------------IsSame ?
bool isSame(struct node*a,struct node*b)
{
if(a==NULL&&b==NULL) return true;

else if(a!=NULL&&b!=NULL)
        return (a->data==b->data&&isSame(a->left,b->left)&&isSame(a->right,b->right));


}

//----------------------------------------------------Main Function
int main(){
struct node*root = newNode(5);
insert(root,6);
insert(root,3);
insert(root,1);
insert(root,7);
cout<<"Inorder Traversal : ";print(root);cout<<endl;
cout<<"Size/No of elements : "<<size(root)<<endl;
cout<<"Max Depth /Levels : "<<maxDepth(root);
cout<<" Min value in Tree : "<<minValue(root)<<endl;

if(hasPathSum(root,18))
cout<<"Path Sum 18 exists "<<endl;
if(!hasPathSum(root,17)) cout<<"Path Sum 17 doesnt exist!"<<endl;

//cout<<"Possible paths are - "<<endl;
//printPaths(root);

//mirror(root);
print(root);

cout<<"Possible number of tree for n=5 "<<countTrees(5);
if(isBST2(root))
    cout<<endl<<"It is BST ";
else
    cout<<endl<<"Not a BST ";
if(isSame(root,root))
  cout<<endl<<"Same Tree ";
return 0;
}
