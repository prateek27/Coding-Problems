#include<iostream>
#include<cstdio>
using namespace std;
//bUG FAILS WHEN K==NO OF NODES

struct node{
int data;
struct node*next;
};
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
};

void push(struct node** head_ref, int new_data)
{

    struct node* new_node =new struct node;
    new_node->data  = new_data;


    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}


void rotate(struct node**head,int k){
if(k==0)
    return ;
struct node*current=*head;
struct node*temp=current;
int count=1;
int i;
while(count<k&&current!=NULL)

   {
        count++;
        current=current->next ;

    }
    if(current==NULL) return;

*head=current->next;
current->next=NULL;

struct node*current2=*head;
while(current2->next!=NULL) current2=current2->next;
current2->next=temp;

}

void printList(struct node*node){

while(node!=NULL){
    cout<<node->data<<" -> ";
    node=node->next;
    }
cout<<"NULL";
}

int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;

    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);

    printf("Given linked list \n");
    printList(head);
    rotate(&head, 4);

    printf("\nRotated Linked list \n");
    printList(head);

    return (0);
}
