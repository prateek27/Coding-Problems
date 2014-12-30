#include<iostream>
using namespace std;

/*
Given a linked list with next and high
pointers, populate high pointers to the
nearest next node with higher value.
*/
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
void populateWithNextHigher(struct node*root){

do{
struct node*current=root;
struct node*higher = NULL ;

while(current!=NULL)
    {
    if(current->data>root->data){
     root->high = current;
     break;
    }

    current=current->next;
    }
root = root->next;
}
while(root);

return ;
}

void printHigher(struct node*root){

while(root!=NULL)
{
    cout<<root->data;
    if(root->high!=NULL)
        cout<<" -> "<<root->high->data;
    cout<<endl;
root=root->next;
}
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
