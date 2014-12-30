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
//-----------------------------------Selection SOrt
void pushNodeAtFront(struct node**head,struct node*n){
    if(*head == NULL){
        *head= n ;
        (*head)->next = NULL;
        return;
    }
    else{
        n->next = (*head);
        (*head) = n;
        }
}

struct node*findAndRemoveMax(struct node**head){

    struct node*current = *head;
    struct node*Mx = current;
    struct node*prevMx=NULL;

    while(current->next!=NULL){

        if(current->next->data > Mx->data)
        {

         Mx = current->next;
         prevMx = current;
        }
    current = current->next;
    }

if(prevMx==NULL){
    *head = (*head)->next;
    Mx->next = NULL; //Detach The node
    return Mx;
}
else{
    prevMx->next = prevMx->next->next;
    Mx->next = NULL; //Detach the node
    return Mx;
    }

}

void selectionSort(struct node**head){

   if(*head==NULL)
    return;

    struct node*output = NULL;
    pushNodeAtFront(&output,findAndRemoveMax(head));
    struct node*current = *head;

    while((*head)!=NULL){
    }

    *head = output;
}

int main(){
struct node*head = NULL;
pushFront(&head,1);
pushFront(&head,5);
pushFront(&head,3);
pushFront(&head,2);
pushFront(&head,4);
print(head);
selectionSort(&head);
cout<<"After Selection sort :"<<endl;
print(head);
return 0;
}
