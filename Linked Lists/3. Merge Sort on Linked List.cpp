#include<iostream>
using namespace std;

// WORKS FINE :D

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
//---------------------------Split in two halves
void splitInTwoHalves(struct node*head,struct node**a,struct node**b){
struct node*fast;
struct node*slow;

if(head==NULL||head->next==NULL)
    { *a=head; *b= NULL;
     return;
    }

else{
struct node*fast=head->next; //Making fast ahead by 1 will stop slow before the mid point.
struct node*slow=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    *a=head;
    *b = slow->next;
     slow->next=NULL;
    }
}
//-----------------------------------Sorted Merge
struct node*sortedMerge(struct node*a,struct node*b){
struct node*result=NULL;
if(a==NULL)
    return b;
if(b==NULL)
    return a;

if(a->data <= b->data){
result = a;
result->next = sortedMerge(a->next,b);
}
else{
result=b;
result->next  = sortedMerge(a,b->next);
}
return (result);
}


//---------------------------------Merge Sort
void MergeSort(struct node**headRef){

struct node*head = *headRef;

if(head==NULL || head->next == NULL)
    return;

struct node*a;
struct node*b;

splitInTwoHalves(head,&a,&b);
//cout<<"SPLIT SUCCESS ";
MergeSort(&a);
MergeSort(&b);

*headRef = sortedMerge(a,b);

}



//------------------------------------Main
int main(){
struct node*head1=NULL;
pushFront(&head1,1);
pushFront(&head1,2);
pushFront(&head1,4);
pushFront(&head1,3);
pushFront(&head1,5);
pushFront(&head1,7);
pushFront(&head1,6);
print(head1);
MergeSort(&head1);
cout<<"After Sorting :";
print(head1);
return 0;
}
