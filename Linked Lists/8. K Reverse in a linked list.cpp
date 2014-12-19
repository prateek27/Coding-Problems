#include<iostream>
#include<stack>
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
//----------------------------------------Reverse
struct node* reverse(struct node*head){
struct node*next ;
struct node*current =head;
struct node* prev = NULL;

    while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev = current;
    current=next;
    }
    //Previous will be at last node , current will be at NULL

return prev;
}
//----------------------------------K reverse
void KReverse(struct node**headRef,int k){
    struct node*current = *headRef;
    struct node*head = *headRef;
    struct node*newHead;

    struct node*next=current;
    bool isFirstTime = true;
    int x=1;
    while(next!=NULL){


    int count = k;
    while(--count && current!=NULL){

        current=current->next;
    }


    next = current->next;
    current->next = NULL;

    if(isFirstTime){
        *headRef = reverse(head);
         head->next = next;
         current = next;
         isFirstTime = false;
    }
    else{
        cout<<current->data<<endl;
        head->next = reverse(head->next);

        }

    }

}
//----------------------------Main


int main(){
struct node*head1=NULL;
struct node*head2=NULL;


pushFront(&head1,8);
pushFront(&head1,7);
pushFront(&head1,6);
pushFront(&head1,5);
pushFront(&head1,4);
pushFront(&head1,3);
pushFront(&head1,2);
pushFront(&head1,1);
print(head1);
int k=3; //K should be the less than the length of linked list;
KReverse(&head1,k);
print(head1);


}



