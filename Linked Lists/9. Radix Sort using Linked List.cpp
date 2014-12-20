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


//-------------------------------Radix Sort on Linked List

void countingSortLL(struct node**head,int exp){
struct node*current=*head;
struct node*bucketHeads[10] = { NULL};
struct node*bucketTails[10] = { NULL};
struct node*next ;

int i ;
while(current!=NULL){
    next = current->next;
    int pos = ((current->data)/exp)%10;

    if(bucketHeads[pos]==NULL)
    {
     current->next=NULL;
     bucketHeads[pos] = current;
     bucketTails[pos] =current;
     }
    else{

    current->next =NULL;
    bucketTails[pos]->next = current;
    bucketTails[pos] = bucketTails[pos]->next;
    }

    current=next;
    }

/* CODE FOR PRINTING BUCKET TABLE
for(i=0;i<10;i++){
    struct node*temp = bucketHeads[i];
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
*/

struct node*newHead = NULL;
struct node*newTail ;

for(i=0;i<10;i++){
    if(bucketHeads[i]==NULL)
        continue;
    else if(bucketHeads[i]!=NULL&&newHead==NULL){
        newHead = bucketHeads[i];
        newTail = bucketTails[i];
    }
    else if(bucketHeads[i]!=NULL&&newHead!=NULL){
    newTail->next = bucketHeads[i];
    newTail = bucketTails[i];
    }
}
*head = newHead;
}


void radixSortLL(struct node**head){

struct node*current = *head;
int biggestNo = -10000;

while(current!=NULL){
biggestNo= max(current->data,biggestNo);
current=current->next;
}

for(int exp=1; biggestNo/exp>0;exp=exp*10){
countingSortLL(head,exp);
    }
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
radixSortLL(&head);
print(head);

}
