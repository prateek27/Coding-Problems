#include<iostream>
using namespace std;
void frontBackSplit(struct node*source,struct node**frontRef,struct node**backRef);
struct node*SortedMerge(struct node*a,struct node*b);

struct node{
int data;
struct node*next;
};

struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->next=NULL;
};

void push(struct node**head,int data){
struct node*temp=newNode(data);
if(*head==NULL)
    *head=temp;
else{
    temp->next=*head;
    (*head)=temp;
    }
}

void print(struct node*head){

while(head!=NULL)
{   cout<<head->data<<" ->";
    head=head->next;

    }
    cout<<"NULL"<<endl;
}

void mergeSort(struct node**head_ref){
struct node*head=*head_ref;
struct node*a;
struct node*b;

if(head==NULL||head->next==NULL)
    return;

frontBackSplit(head,&a,&b);
mergeSort(&a);
mergeSort(&b);

*head_ref=SortedMerge(a,b);
}
void frontBackSplit(struct node*source,struct node**frontRef,struct node**backRef){
struct node*head=source;
struct node*fast=   head->next;
struct node*slow =  head;

while(fast!=NULL)
{   fast=fast->next;
    if(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }

}
*frontRef=head;
*backRef=slow->next;
slow->next=NULL;

}


struct node*SortedMerge(struct node*a,struct node*b)
{   struct node*result;

if(a==NULL) return b;
if(b==NULL) return a;

if(a->data<=b->data)
        {
            result=a;
            result->next=SortedMerge(a->next,b);
        }
else{
    result=b;
    result->next=SortedMerge(a,b->next);

}
return result;
};



int main(){
struct node*head=NULL;
for(int i=1;i<=10;i++)
    push(&head,i);

print(head);
mergeSort(&head);
print(head);

}
