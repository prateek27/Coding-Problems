#include<iostream>
using namespace std;

struct node{
int info;
struct node*next;
};
struct node*head=NULL;


void insert(int data){
struct node*temp=new node;
temp->info=data;
temp->next=NULL;

if(head==NULL)
     head=temp;

else {
    struct node*current=head;
    while(current->info>data)
    {current=current->next;}

     temp->next=current->next;
     current->next=temp;
    }
}



void print(){
struct node*current=head;
while(current!=NULL)
{
    cout<<current->info<<" ";
    current=current->next;
}

}
void insert_front(struct node**head,int data)
{struct node*temp=new node;
temp->info=data;
temp->next=*head;
*head=temp;

}


int main(){
int n;
insert(n);

while(n!=0){
    cin>>n;
    if(n>head->info) insert_front(&head,n);
    else
        insert(n);
print();
cout<<endl;
}

return 0;
}
