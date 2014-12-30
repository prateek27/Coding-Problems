#include<iostream>
using namespace std;


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

int getSize(struct node*head){
if(head==NULL)
return 0;
else{
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
    }
}
//-----------------------------------Insertion Sort
void sortedInsert(struct node**head,struct node*nodeToInsert){

//No Node
if(*head==NULL){
    *head = nodeToInsert;
    return ;
}
// Node greater than head
else if((*head)->data > nodeToInsert->data){
    nodeToInsert->next = *head;
    *head = nodeToInsert;
    return;
}
//Insert in middle
else{
    struct node*current = *head;
    struct node*prev ;
    while(current!=NULL&&nodeToInsert->data > current->data){
        prev = current;
        current = current->next;
    }
    prev->next= nodeToInsert;
    nodeToInsert->next = current;
    return;
    }
}
//--------------------
void insertionSort(struct node**head){
struct node*output = NULL;
struct node*current = *head;
struct node*next = (*head)->next;
//If one node return
if(next==NULL)
    return;
// Detach a node from front , insert into sorted linked list formed.
else{
    while(current!=NULL){
        next = current->next; //Save the next
        current->next = NULL; //Detach the node
        sortedInsert(&output,current);
        current = next ;
    }
    *head = output;
    }
}

int main(){
struct node*head = NULL;
pushFront(&head,1);
pushFront(&head,5);
pushFront(&head,3);
pushFront(&head,2);
pushFront(&head,4);
print(head);
insertionSort(&head);
cout<<"After insertion sort :"<<endl;
print(head);

return 0;
}
