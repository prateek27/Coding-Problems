#include<iostream>
#include<cmath>
using namespace std;
/*Input:
  First List: 5->6->3  // represents number 563
  Second List: 8->4->2 //  represents number 842
Output
  Resultant list: 1->4->0->5  // represents number 1405
*/

//This program is faulty and needs debugging.

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
//---------------------------------Get Size
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
//-----------------------------------------Swap heads
void swapHeads(struct node**a,struct node**b){
struct node*temp = *a;
*a = *b ;
*b = temp;
return;
}

//-------------------------------------------------Prototypes
void addCarryToRemaining(struct node*head,struct node*current,int *carry,struct node**result);
struct node* addSameSizeLists(struct node*a,struct node*b,int *carry);

//-----------------------------------Add Linked Lists
struct node* addLinkedLists(struct node*a,struct node*b){
struct node*result=NULL;
int len1 = getSize(a);
int len2 = getSize(b);

int carry=0;
if(len1==len2){
result = addSameSizeLists(a,b,&carry);
}
else{
int diff = abs(len1-len2);

if(len2>len1){
    swapHeads(&a,&b);
}
//Now bigger list is at  top
struct node*current = a;
while(diff--){
current=current->next;
}
int carry=0;
result = addSameSizeLists(current,b,&carry);
addCarryToRemaining(a,current,&carry,&result);
    }
if(carry>0)
    pushFront(&result,carry);

}
//---------------------------------Add Same Size
struct node* addSameSizeLists(struct node*a,struct node*b,int*carry){

if(a==NULL||b==NULL)
    return NULL;

struct node*result;
result->next = addSameSizeLists(a->next,b->next,carry);
int sum = a->data + b->data + *carry;
*carry =  sum/10;
sum%=10;
result->data = sum;

return result;
}
//---------------------------------------Add Carry to Remaining
void addCarryToRemaining(struct node*head,struct node*current,int *carry,struct node**result){

if(head!=current){
    addCarryToRemaining(head->next,current,carry,result);
    int sum = head->data + *carry;
    *carry = sum/10;
    sum = sum%10;
    pushFront(result,sum);
    }
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
addLinkedLists(head1,head2);

return 0;
}
