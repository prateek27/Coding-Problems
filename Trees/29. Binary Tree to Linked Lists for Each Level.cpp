#include<iostream>
#include<queue>
#include<vector>
using namespace std;


/* Author : Prateek Narang */
/* NOTE : THIS CODE SNIPPET IS BUGGY */


struct node{
int data;
node*left,*right;
    node(int data){
        this->data = data;
        left=NULL;
        right = NULL;
    }
};

struct node* makeTree(int *a,int low,int high){
    struct node*root;
    int mid;
    if(low<=high){
        mid = (low + high)/2;
        root = new node(a[mid]);
        root->left = makeTree(a,low,mid-1);
        root->right = makeTree(a,mid+1,high);
        return root;
    }
    else{
        return NULL;
    }
}
int getHeight(struct node*root){
    if(root==NULL)
        return 0;
    return max(getHeight(root->left),getHeight(root->right))+1;
}

void binaryTreeToLists(struct node*root){
    int height = getHeight(root);
    cout<<height<<endl;
    /*
    vector<int> v[height+1];
    int level=0;

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        int data = temp->data;
        q.pop();

        if(temp==NULL){
     //       cout<<endl;
            if(!q.empty())
                {q.push(NULL);
                  level++;
                }

        }
        else{
        //cout<<temp->data<<" ";
        //v[0].push_back(data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
            }
       }
    }

    for(int i=0;i<height;i++){
       for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<"->";
        }
    cout<<endl;
    }*/
}



void print(struct node*root){
    //Use Level order Traversal to print the tree.
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);

        }
        else{
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
            }
       }
    }
}

void printPostorder(struct node*root){
if(root){
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
    }
}

int main(){
int a[10]={1,2,3,4,5,6,7,8,9,10};
struct node*tree = makeTree(a,0,9);
binaryTreeToLists(tree);
return 0;
}

