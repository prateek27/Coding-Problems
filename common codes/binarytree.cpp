#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;
Node* newnode(int d)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data=d;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);  
     printInorder(node->right);
}
void leftview(Node* node)
{
	if(node==NULL)
		return;
	printf("%d ",node->data);
	if(node->left!=NULL)
		leftview(node->left);
	else
		leftview(node->right);		
}
void rightview(Node* node)
{
	if(node==NULL)
		return;
	printf("%d ",node->data);
	if(node->right!=NULL)
		rightview(node->right);		
	else 
		rightview(node->left);
}
void levelorder(Node* node)
{
	queue<Node*> Q;
	Q.push(node);
	while(!Q.empty())
	{
		Node* cur=Q.front();
		Q.pop();
		printf("%d ",cur->data);
		if(cur->left!=NULL)
			Q.push(cur->left);
		if(cur->right!=NULL)
			Q.push(cur->right);
	}	
}
void levelorder2(Node* node)
{
	int p1,p2;
	queue<Node*> Q;
	Q.push(node);
	p1=1;
	p2=0;
	while(!Q.empty())
	{
		while(p1)
		{
		Node* cur=Q.front();
		Q.pop();
		printf("%d ",cur->data);
		if(cur->left!=NULL)
			{
			Q.push(cur->left);
			p2++;
			}
		if(cur->right!=NULL)
			{
			Q.push(cur->right);
			p2++;
			}
		p1--;	
		}
		printf("\n");
		p1=p2;
		p2=0;
	}	
}

int main()
{
	Node *root=newnode(1);
	root->left=newnode(18);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->left->left->right=newnode(6);
//	printInorder(root);
	leftview(root);
	printf("\n");
	rightview(root);
	printf("\n");
	levelorder(root);
	printf("\n");
	levelorder2(root);
	printf("\n");
	return 0;
}
