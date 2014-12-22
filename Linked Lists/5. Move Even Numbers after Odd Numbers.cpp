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
//----------------------------------------Reverse
void reverse(struct node**head){
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
//----------------------------------Move Even Numbers to end
void moveEven(struct node**head){

    struct node*tail= *head ;
    struct node*newHead=NULL;
    struct node*current = *head;
    struct node*prev = *head ;
    struct node*even;
    struct node*next ;

    bool isEven = true ; //IsEven is true if whole list is even
    while(current!=NULL) //Tail now points to last Element
        { tail= current;
          if(current->data % 2 == 1)
                isEven =false;
          current=current->next;
        }

    if(isEven)
        return ;

    current= *head;

    while(current!=NULL){


        if(current->data%2==0)
            {
            if(current==*head){
                next = current->next;
                current->next = newHead;
                newHead = current;
                current=next;
                *head = current;
            }
            else{
                next = current->next;
                prev->next = next;

                current->next=newHead;
                newHead = current;

                current = next;
                }

            }
        else{
            prev = current;
            current=current->next;
            }

    }
    reverse(&newHead);
    prev->next = newHead;

}

//----------------------------Main


int main(){
struct node*head;
struct node*tail;
pushFront(&head,8);
pushFront(&head,1);
pushFront(&head,2);
pushFront(&head,3);
pushFront(&head,4);
pushFront(&head,6);
print(head);
moveEven(&head);
print(head);
}


