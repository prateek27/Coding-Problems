#include<iostream>
using namespace std ;

struct node{
int data;
struct node*next;
};
//-----------------------------------------New Node
struct node*newNode(int data){
struct node*temp = new struct node;
temp->data = data;
temp->next = NULL;
return temp;
}

//----------------------------------------------Push Front
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
//---------------------------------------Print
void print(struct node*head){
struct node*current = head;
while(current!=NULL){
 cout<<current->data<<"->";
 current=current->next;
    }
cout<<endl;
}

//-----------------------------------Get Mid

struct node*getMidBreakMid(struct node*head){
struct node*fast = head;
struct node*slow = head;
struct node*prev ;

while(fast!=NULL){
    prev=slow;
    fast=fast->next;
    if(fast!=NULL){
        slow=slow->next;
        fast = fast->next;
    }
}
    prev->next = NULL;
    return slow;
}

//-------------------------------Alternating merge

void alternatingMerge(struct node*head){

struct node*current  = head;
struct node * mid = getMidBreakMid(head);
struct node*next ;
struct node*next2;

while(mid!=NULL){
    next = current->next;
    next2= mid->next;
    current->next = mid;
    mid->next = next;
    current = next;
    mid = next2;
    }
}



int  main(){
struct node*head = NULL;
//Note List is of the form a1-a2-a3.....-an-b1-b2-b3.....-bn  (Even elements in total)
pushFront(&head,6);
pushFront(&head,4);
pushFront(&head,2);
pushFront(&head,5);
pushFront(&head,3);
pushFront(&head,1);
print(head);
alternatingMerge(head);
//print(getMidBreakMid(head));
print(head);
}
