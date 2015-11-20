#include<iostream>
#include<stdlib.h>
using namespace std;


struct node{
int info;
struct node*next;
};
struct node*head=NULL;
struct node*tail=NULL;
//--------------------------------------------------------------------------INSERTION
void insert(int x){

if(head==NULL)
{
 struct node*newNode=new node;
 newNode->info=x;
 newNode->next=NULL;
 head=newNode;
 tail=newNode;
}
else{
    struct node*newNode=new node;

    newNode->info=x;
    newNode->next=NULL;
    tail->next=newNode;
    tail=newNode;
}

}
//--------------------------------------------------------------------------DISPLAY
void display(struct node*head)
{
    struct node*current=head;

    while(current!=NULL){ cout<<current->info ; current=current->next;}
}
//---------------------------------------------------------------------------DELETION
void deleteLL(struct node**head){
struct node*current=*head;
struct node*next;

    while(current!=NULL){
        next=current->next;
        delete current;
        current=next;}

*head=NULL;
}
//------------------------------------------------------------------------REMOVE FRONT
int pop(struct node**head){
struct node*temp=*head;
int result=temp->info;
*head=temp->next;
delete temp;
}
//--------------------------------------------------------------------------REVERSE LINKED LIST
void reverse(struct node**head){

}
//--------------------------------------------------------------------------REMOVE DUPLICATES(sorted)
void removeDuplicates(struct node*head){
struct node*current=head;
if(current==NULL) return ;
while(current->next!=NULL)
{
    if(current->info==current->next->info)
    {
        struct node*temp=current->next->next;
        delete current->next;
        current->next=temp;

    }
    else
        current=current->next;

}

}
//---------------------------------------------------------------------------Front Back Split
void frontBackSplit(struct node*source,struct node**frontRef,struct node**backRef)
{
struct node*fast;
struct node*slow;

if(source==NULL||source->next==NULL){
    *frontRef=source;
    *backRef=NULL;
}
else{
    slow=source;
    fast=source->next;

    while(fast!=NULL)
    {
    fast=fast->next;
    if(fast!=NULL){
    slow=slow->next;
    fast=fast->next;
    }
  }
**frontRef=source;
**backRef=slow->next;
slow->next=NULL;
}
}



int main()
{

    int n,x;
    cout<<"Enter the number of nodes";
    cin>>n;
    cout<<"Enter elements";
    for(int i=0;i<n;i++){
    cin>>x;
    insert(x);
    }

    display(head);
    cout<<"Head"<<pop(&head)<<endl;
    display(head);



    removeDuplicates(head);
    display(head);
    cout<<"Linked List Deleted";
    deleteLL(&head);
    display(head);


return 0;
}
