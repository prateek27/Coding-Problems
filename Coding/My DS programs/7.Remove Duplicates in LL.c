#include<iostream>
using namespace std;


struct node{
int data;
struct node*next;
}

struct node*getNode()
{
 struct node*newNode=malloc(sizeof(struct node));
 node->next=NULL;
 return newNode;
}

void insertAfter(struct node*node,int data)
{
 struct node*p=getNode();
 p->info=x;
 p->next=node->next;
 node->next=p;
}

int main()
{
    struct node*head;
    struct node*temp=new node;
    temp->info=0;
    head=temp;

    cout<<"Enter the number of nodes";
    cin>>n;
    for(int i=0;i<n;i++)
    {
     struct node*p=new node;
     temp->next=p;
     p->info=i;
     temp=p;
    }

    struct node*current=head;
    while(current!=NULL){ cout<<current->info; current=current->next; }



return 0;
}
