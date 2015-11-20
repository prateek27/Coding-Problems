#include<iostream>
using namespace std;

struct node{
int data;
struct node*next;
};

struct node*head=NULL;
int x,y,z;

struct node*newNode(int data){   //--------------------Function to create a new node
struct node*node=new struct node;
node->data=data;
node->next=NULL;
return node;
};

void push(struct node**head,int data){  //---------------------Push at front
if(head==NULL)
    *head=newNode(data);

else{
    struct node*temp=newNode(data);
    temp->next=*head;
    *head=temp;
    }
}

void sort012(struct node*head){
struct node*current=head;

while(current!=NULL)
{
    if(current->data==0) x++;
    else if(current->data==1) y++;
    else z++;
    current=current->next;
}
current=head;

for(int i=0;i<x;i++)
    current->data=0,current=current->next;

for(int i=x;i<x+y;i++)
    current->data=1,current=current->next;

for(int i=x+y;i<x+y+z;i++)
    current->data=2,current=current->next;

}

void print(){
struct node*current=head;
while(current!=NULL)
    {
    cout<<current->data<<"->";
    current=current->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    push(&head,2);
    push(&head,0);
    push(&head,1);
    push(&head,1);
    push(&head,0);
    push(&head,0);
    push(&head,2);
    push(&head,0);
    push(&head,1);

print();
cout<<"Sorted Linked List "<<endl;
sort012(head);
print();
}
