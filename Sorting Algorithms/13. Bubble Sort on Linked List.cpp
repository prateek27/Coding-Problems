#include<iostream>
using namespace std;

//----------------------------Basics
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
    cout<<endl;
}


//-------------------------------Bubble Sort on Linked List
void bubbleSortLL(struct node**head){


}


int main(){
struct node*head = NULL;
pushFront(&head,13);
pushFront(&head,28);
pushFront(&head,35);
pushFront(&head,101);
pushFront(&head,56);
pushFront(&head,177);
pushFront(&head,117);
pushFront(&head,23);
print(head);
bubbleSortLL(&head);
print(head);
}
