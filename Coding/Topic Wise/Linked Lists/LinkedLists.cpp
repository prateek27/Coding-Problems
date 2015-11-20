#include<iostream>
using namespace std;

struct node{
int data;
struct node*next;
};

struct node*newNode(int data)
{
    struct node*node=new struct node;
    node->data=data;
    node->next=NULL;
    return node;
}
//----------------------------------------------Add at front

void addAtFront(struct node**head,int data){

struct node*temp=newNode(data);
temp->next= *head;
*head=temp;
}
//-------------------------------------------Add at the end
void addAtEnd(struct node*tail,int data){

tail->next=newNode(data);
tail=tail->next;

}


//-----------------------------------------print Fucntion
void print(struct node*head){
struct node*temp=head;

while(temp!=NULL)
{
    cout<<temp->data<<" -> ";
    temp=temp->next;
}

}

int main(){

struct node*head=newNode(5);
struct node*tail=head;
addAtFront(&head,3);
addAtFront(&head,1);
addAtFront(&head,7);
//print(head);
addAtEnd(tail,10);
addAtEnd(tail,11);
addAtEnd(tail,12);
print(head);

return 0;
}


