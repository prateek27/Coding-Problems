#include<iostream>
using namespace std;

struct node{
int data;
struct node*next,*prev;
};
struct node*head=NULL;
struct node*last=NULL;
//---------------------------------NewNode
struct node*newNode(int data){
struct node*node= new struct node;
node->data=data;
node->next=NULL;
node->prev=NULL;
};
//------------------------------------------InsertFront
void insert_front(struct node**head,int data){
if(*head==NULL)
    {
        *head=newNode(data);
        last=*head;
    }
else{
    struct node*temp=newNode(data);
    (*head)->prev=temp;
    temp->next=*head;
    *head=temp;
    }
};

//----------------------------------------Print
void print(){
struct node*current=head;
while(current!=NULL)
{
    cout<<current->data<<" <=> ";
    current=current->next;
}
cout<<endl;
}
//-------------------------------------------Insert End
void insert_end(struct node**head,int data){
if(last==NULL)
    last=newNode(data);
else{
    struct node*temp=newNode(data);
    temp->prev=last;
    last->next=temp;
    last=temp;
    }
};

//----------------------------------------Insert After
void insert_after(struct node*head,int key,int data){
struct node*temp;
temp=newNode(data);
struct node*current=head;
while(current!=NULL&&current->data!=key){
    current=current->next;
    }
    if(current!=NULL)
    {
    current->next->prev=temp;
    temp->next=current->next;
    temp->prev=current;
    current->next=temp;
    }
    else
        cout<<"NOT FOUND ";
}
//-----------------------------------------Reverse A linked list
void reverse(struct node**head){
struct node*current=*head;
struct node*temp=NULL;

while(current!=NULL){
    temp=current->prev;
    current->prev=current->next;
    current->next=temp;
    current=current->prev;
}
if(temp!=NULL)
    *head=temp->prev;  //This is important

}

int main(){

insert_front(&head,3);
insert_front(&head,7);
insert_front(&head,8);
insert_end(&head,15);
insert_end(&head,20);
insert_after(head,8,13);

print();

reverse(&head);
print();

return 0;
}
