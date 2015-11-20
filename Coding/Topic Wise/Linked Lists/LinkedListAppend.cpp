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


int main(){

struct node*head1=newNode(1);
insert(&head1,2);
insert(&head1,3);
print(head1);

struct node*head2=newNode(4);
insert(&head2,5);
insert(&head2,6);
print(head2);

append(&head1,&head2);
print(head1);

return 0;
}
