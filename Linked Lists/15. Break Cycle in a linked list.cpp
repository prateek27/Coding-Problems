#include<iostream>
using namespace std;

/*
Given a linked list C program to Delete a node from SLL, in
which the last node points to the first
middle node */
/* Time Complexity O(n^2)*/

struct node{
int data;
struct node*next;
struct node*high;
};

struct node* createNode(int data){
struct node* n = new node;
n->data = data;
n->next = NULL;
n->high = NULL;
return n;
}
//------------------------------------------------Push front
void pushFront(struct node**head,int data){
struct node* first = createNode(data);

if(*head==NULL){
 *head = first;
 }
else{
    first->next = (*head);
    *head = first;
    }
}
//----------------------------------------Get mid
struct node*getMid(struct node*root){
    struct node*fast = root;
    struct node*slow = root;

    while(fast==NULL){
        fast = fast->next;
        if(fast){
            fast=fast->next;
            slow= slow->next;
        }
    }
return slow;
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


//--------------------------------------------Populate with next higher
void deleteNode(int key){


return ;
}


int  main(){
struct node*head = NULL;
pushFront(&head,6);
pushFront(&head,7);
pushFront(&head,4);
pushFront(&head,5);
pushFront(&head,1);
pushFront(&head,2);
print(head);
cout<<endl;
populateWithNextHigher(head);
printHigher(head);
}
