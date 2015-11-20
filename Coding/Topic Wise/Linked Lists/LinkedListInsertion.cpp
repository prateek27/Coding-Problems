#include<iostream>
using namespace std;
//--------------Node Structure
struct node{
int data;
struct node*next;
};
struct node*head=NULL;
struct node*last=NULL;
//----------------------------New Node function
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->next=NULL;
return node;
};
//-----------------------------------Reverse a linked list
void reverse(struct node**head){
struct node*current=*head;
struct node*next;
struct node*result=NULL;

while(current!=NULL){
    next=current->next;
    current->next=result;
    result=current;
    current=next;
    }
*head=result;
}

//-----------------------------------------Insert at Front
void insert_front(struct node**head,int data){
if(*head==NULL)
  { *head=newNode(data);
    last = *head;}
else{
        struct node*temp=newNode(data);
        temp->next=*head;
        *head=temp;
    }
}
//-------------------------------------------Insert at end
void insert_end(struct node**head,int data){
struct  node*temp=newNode(data);
last->next=temp;
last=temp;
}

//----------------------------------------------Void print
void print(struct node*head){
struct node*temp=head;
while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp=temp->next;
}
cout<<"NULL"<<endl;
}
//-------------------------------------------Main
int main(){
insert_front(&head,5);
insert_front(&head,6);
insert_front(&head,11);
insert_end(&head,30);
insert_end(&head,18);
print(head);
reverse(&head);
print(head);
return 0;
}
