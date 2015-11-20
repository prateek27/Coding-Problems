#include<iostream>
#include<cstdio>
using namespace std;

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
    /* allocate node */
    struct node* new_node =new struct node;
 /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}


void pairWiseSwap(struct node**head){
    //struct node*current=*head;
    struct node*current=(*head)->next;
    struct node*prev=*head;

    *head=current;

    while(true)
    {
    struct node*next=current->next;
    current->next=prev;
    if(next==NULL||next->next==NULL) {     }




    }

}

void printList(struct node*node){

while(node!=NULL){
    cout<<node->data;
    node=node->next;
    }
}

int main()
{
    struct node *start = NULL;

    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);

    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);

    pairWiseSwap(&start);

  printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);

    getchar();
    return 0;
}
