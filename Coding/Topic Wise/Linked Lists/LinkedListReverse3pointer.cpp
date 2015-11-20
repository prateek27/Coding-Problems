#include<iostream>
using namespace std;

struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->next=NULL;
return node;
};

void insert(struct node**head,int data){
if(*head==NULL){
    *head=newNode(data);
    }
else{
    struct node*current=*head;
    while(current->next!=NULL)
    current=current->next;

current->next=newNode(data);
}

}
void print(struct node*head){
struct node*node=head;
while(node!=NULL)
    {
    cout<<node->data<<" -> ";
    node=node->next;
    }
    cout<<"NULL"<<endl;
}
void append(struct node**a,struct node**b)
{
    if(*a==NULL)
        *a=*b;
    else{
            struct node*current=*a;
    while(current->next!=NULL) current=current->next;
    current->next=*b;
    }
*b=NULL;
}
//-------------------Reverse 3 pointer
void reverse(struct node**head){
struct node*result=NULL;
struct node*current=*head;
struct node*next;

while(current!=NULL)
{
    next=current->next;
   current->next=result;
    result=current;
    current=next;
}
*head=result;
}
//------------------------ Reverse front ,back , middle
void Reverse2(struct node**headRef){
    struct node*middle=*headRef;
    struct node*front=middle->next;
    struct node*back=NULL;

    while(1){
        middle->next=back;
        if(front==NULL) break;

        back=middle;
        middle=front;
        front=front->next;
        }
        *headRef=middle;
    }

void ReverseRecursion(struct node**headRef){
struct node*first;
struct node*rest;

if(*headRef==NULL) return;

first=*headRef;
rest = first->next;

}
int main(){

struct node*head1=newNode(1);
insert(&head1,2);
insert(&head1,3);
print(head1);

struct node*head2=newNode(4);
insert(&head2,5);
insert(&head2,6);
print(head2);

cout<<"Appended List : ";
append(&head1,&head2);
print(head1);

cout<<"Reverse List ";
reverse(&head1);
print(head1);

cout<<"Reverse Second : ";
reverse(&head1);
print(head1);
return 0;
}
