#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

/* Utility function to print a singly linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    printf("\n");
}


void skipMdeleteN(struct node*head,int m,int n){
int i,j;
struct node*current=head;

while(current!=NULL){

    for(i=1;i<m&&current!=NULL;i++)      //Stop before one node. ->NODE->NodeDel       (stop at fist pointer)
    {
        current=current->next;
    }
    if(current==NULL) return;

    struct node*t=current->next;

    for(j=0;j<n&&t!=NULL;j++)
    {
        struct node*temp=t->next;
        delete t;
        t=temp;
    }
    //cout<<"C"<<current->data;
    //cout<<"T"<<t->data;

    current->next=t;              //This is important
    current=current->next;
    }
}
int main()
{
    /* Create following linked list
      1->2->3->4->5->6->7->8->9->10 */
    struct node* head = NULL;
    int M=2, N=3;
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("M = %d, N = %d \nGiven Linked list is :\n", M, N);
    printList(head);

    skipMdeleteN(head, M, N);

    printf("\nLinked list after deletion is :\n");
    printList(head);

    return 0;
}
