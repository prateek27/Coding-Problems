#include<iostream>
using namespace std;
/* Easy One - Numbers as given (LSB at head of linked list)
 First List: 7->5->9->4->6  // represents number 64957
  Second List: 8->4 //  represents number 48
Output
  Resultant list: 5->0->0->5->6  // represents number 65005
*/

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

//---------------------------------Addition Subroutine
struct node* addTwoLinkedLists(struct node*a,struct node*b){

if(b==NULL)
    return a;
if(a==NULL)
    return b;

struct node*result=NULL;
struct node*current;

int sum=0,carry=0;
while(a!=NULL&&b!=NULL){
sum=a->data + b->data+carry;
carry = sum/10;
sum = sum%10;

if(result==NULL){
    result=newNode(sum);
    current=result;
 }
 else{
    current->next=newNode(sum);
    current=current->next;
 }
    a=a->next;
    b=b->next;

}
cout<<"Data Printing:"<<endl;
struct node *temp=NULL;
if(a!=NULL) temp=a;
if(b!=NULL) temp=b;

while(temp!=NULL){
sum=temp->data+carry;
carry = sum/10;
sum = sum%10;
current->next=newNode(sum);
current=current->next;
temp=temp->next;
}
if(carry>0)
current->next = newNode(carry);

print(result);

}



//------------------------------------Main
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
//pushFront(&head2,9);
//4321 + 9865 = 3296 (LSB on extreme left)
addTwoLinkedLists(head1,head2);

return 0;
}
