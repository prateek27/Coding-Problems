#include<iostream>
using namespace std;


//---------------------Binary Search
int BinarySearch(int *a,int key,int low,int high){
    while(low<=high){
    int mid = (low+high)/2;
    if(a[mid]==key)
        return mid;
    else if(a[mid]>key)
        high = mid-1;
    else
        low = mid+1;
    }
return -1; //Not found
}

struct node{
int data;
struct node*left;
struct node*right;
};

struct node*constructTree(int *pre,int *in,int low,int high,int &pre_index,int n){

if(pre_index>=n)
    return NULL;

if(low>high){
    return NULL;
}

else if(low<=high){

    struct node* node = new struct node;
    node->data = pre[pre_index];
    int index_in = BinarySearch(in,pre[pre_index],low,high);
    pre_index++;
    node->left = constructTree(pre,in,low,index_in-1,pre_index,n);
    node->right = constructTree(pre,in,index_in+1,high,pre_index,n);
    return node;
    }
}


void printInorder(struct node*root){
if(root==NULL)
    return;

printInorder(root->left);
cout<<root->data<<" ";
printInorder(root->right);

}

int main(){
int preorder[] = {6,3,1,4,7,8,9};
int inorder[] ={1,3,4,6,7,8,9};
int n = sizeof(inorder)/sizeof(int);
int pre_index = 0;
struct node*root = constructTree(preorder,inorder,0,n-1,pre_index,n);
printInorder(root);
}
