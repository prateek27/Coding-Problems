#include<iostream>
using namespace std;

//-------------------------------------------------------------Node Structure
struct node{
int data;
struct node*next;
};
    struct node*head=NULL;
//--------------------------------------------------------------New Node
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->next=NULL;
return node;
};
//--------------------------------------------------------------Sorted Insert
void sortedInsert(struct node**headRef,int data){
struct node*current =*headRef;

if(*headRef==NULL)
{
*headRef=newNode(data);
}

else if(data>(*headRef)->data) {
struct node*temp=newNode(data);
temp->next=*headRef;
*headRef=temp;
}

else{
current = *headRef;
while (current->next!=NULL && current->next->data>data) {
current = current->next;
}


        struct node*temp=newNode(data);
            temp->next=current->next;
            current->next=temp;
    }
}

//----------------------------------------------InsertSotrt
void InsertSort(struct node**headRef){
        struct node*newHead=NULL;
        struct node*current=*headRef;

while(current!=NULL)
{
    sortedInsert(&newHead,current->data);
    current=current->next;

}
*headRef=newHead;
}

//---------------------------------------Print
void print(struct node*head){
struct node*node=head;
while(node!=NULL)
    {
    cout<<node->data<<" -> ";
    node=node->next;
    }
    cout<<"NULL";
}

int main(){

struct node*head=newNode(5);
head->next=newNode(6);
head->next->next=newNode(3);

InsertSort(&head);
print(head);
return 0;
}
