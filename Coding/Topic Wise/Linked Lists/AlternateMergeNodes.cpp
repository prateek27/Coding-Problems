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

void merge(struct node*p,struct node**q){

struct node*p_current=p;
struct node*q_current=*q;
struct node*p_temp,*q_temp;

while(p_current!=NULL&&q_current!=NULL)
 {
    p_temp=p_current->next;
    q_temp=q_current->next;

    p_current->next=q_current;
    q_current->next=p_temp;

    p_current=p_temp;
    q_current=q_temp;

 }
*q=q_temp;
}

int main()
{
     struct node *p = NULL, *q = NULL;
     push(&p, 3);
     push(&p, 2);
     push(&p, 1);
     printf("First Linked List:\n");
     printList(p);

     push(&q, 8);
     push(&q, 7);
     push(&q, 6);
     push(&q, 5);
     push(&q, 4);
     printf("Second Linked List:\n");
     printList(q);

     merge(p, &q);

     printf("Modified First Linked List:\n");
     printList(p);

     printf("Modified Second Linked List:\n");
     printList(q);

     getchar();
     return 0;
}
