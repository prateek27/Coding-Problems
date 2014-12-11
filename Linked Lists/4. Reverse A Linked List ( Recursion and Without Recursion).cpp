#include<iostream>
using namespace std;
/* Reverse a linked list using Recursion and With recursion */


struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*temp = new struct node;
temp->data = data;
temp->next = NULL;
return temp;
}

void pushFront(struct node**head,int data){
struct node* first = newNode(data);

if(*head==NULL){
 *head = first;
}
else{
    first->next = (*head);
    *head = first;
    }
}

void print(struct node*head){
struct node*current = head;
while(current!=NULL){
 cout<<current->data<<"->";
 current=current->next;
    }
}

//-------------------------------------------------------Iterative Reverse
void itrReverse(struct node**head){
struct node*next ;
struct node*current = *head;
struct node* prev = NULL;

    while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev = current;
    current=next;
    }
    //Previous will be at last node , current will be at NULL
*head = prev;
}
//-------------------------------------------------Recursive Reverse
void recursiveReverse(struct node**head){
struct node*first = *head;
struct node*rest;
rest=first->next;
if(rest==NULL)
    return ;
recursiveReverse(&rest);
first->next->next = first;
first->next = NULL;

*head = rest;
}

int main(){
struct node*head1=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,3);
pushFront(&head1,4);
struct node*head2=NULL;
pushFront(&head2,5);
pushFront(&head2,6);
pushFront(&head2,8);
print(head1);
itrReverse(&head1);
cout<<endl<<"REVERSE :";
print(head1);
recursiveReverse(&head1);
cout<<endl<<" Recursive REVERSE :";
print(head1);
return 0;
}
