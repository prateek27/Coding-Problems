#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct node{
int data;
struct node*left,*right;
};

struct node*newNode(int data)
{
    struct node*node=new struct node;
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void getVerticalOrder(struct node*node,int hd,map<int,vector<int> > &m)
{

    if(node==NULL)
        return;
    m[hd].push_back(node->data);

    getVerticalOrder(node->left,hd-1,m);
    getVerticalOrder(node->right,hd+1,m);

}

void printVerticalOrder(struct node*root)
{
    map<int,vector<int> > m;
    int hd=0;
    getVerticalOrder(root,0,m);

    map<int,vector<int> >::iterator it;

    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<" ";
        cout<<endl;
        }

}

int main(){

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;

}
