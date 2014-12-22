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
//----------------------------------------Loop Detections
bool detectLoop(struct node*head){

struct node*fast = head;
struct node*slow = head;

while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(fast==slow){
        cout<<"LOOP FOUND"<<endl;
        return true;
    }
}
cout<<"NO LOOP"<<endl;
return false;
}
int main(){
struct node*head = NULL;
pushFront(&head,5);
pushFront(&head,4);
pushFront(&head,3);
pushFront(&head,2);
pushFront(&head,1);
pushFront(&head,0);
print(head);
detectLoop(head);
cout<<"After Adding Loop : ";
head->next->next->next->next->next->next = head->next;  //5 now points to 1
//print(head); //Prints the infinite loop
detectLoop(head);

return 0;
}
