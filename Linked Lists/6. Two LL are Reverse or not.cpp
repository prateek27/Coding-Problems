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
bool areReverseUsingStack(struct node*head1,struct node*head2){
stack<node*> s;

while(head1!=NULL){
s.push(head1);
head1= head1->next;
}

while(!s.empty())
{
struct node* t = s.top();
s.pop();
if(head2==NULL)  //If list is finished and 1 is not finished
    return false;

 if(t->data!=head2->data)
    {return false;}
head2=head2->next;
}

if(head2!=NULL) //If list 2 is not finished after list 1 is finished
    return false;

return true;
}
//----------------------------------------------------Bool are reverse using recusion BUGGY CODE
bool areReverseUsingRecursion(struct node*head1,struct node**head2){

    if(head1==NULL)
        return true;
    if(areReverseUsingRecursion(head1->next,head2)&&head1->data==(*head2)->data)
    { *head2 = (*head2)->next ; return true;}

    else{
        return false ;
        }

}

//----------------------------Main


int main(){
struct node*head1=NULL;
struct node*head2=NULL;

pushFront(&head2,1);
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,3);

pushFront(&head2,3);
pushFront(&head2,2);
pushFront(&head2,1);


if(areReverseUsingStack(head1,head2))
    cout<<"YES,They are reverse of each other using Stack";
else{
    cout<<"NO , Not reverse of each other";
}
if(areReverseUsingRecursion(head1,&head2))
    cout<<"YES,They are reverse of each other using Recursion";
else{
    cout<<"NO , Not reverse of each other";
}



}


