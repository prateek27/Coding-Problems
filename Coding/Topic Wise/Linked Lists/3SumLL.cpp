#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
//Given 3 linked lists .http://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/



/* Link list node */
struct node
{
    int data;
    struct node* next;
};

/* A utility function to insert a node at the begining of a linked list*/
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}


bool isSumSorted(struct node *headA, struct node *headB,
                 struct node *headC, int givenNumber)
{
    struct node*a=headA;

    int sum;
    while(a!=NULL)
    {
        struct node*b=headB;
        struct node*c=headC;

        while(b!=NULL&&c!=NULL)
        {

        sum=a->data+b->data+c->data;
        if(sum==givenNumber)
                {
                printf ("Triplet Found: %d %d %d ", a->data, b->data, c->data);
                return true;
                }
        if(sum<givenNumber)
            b=b->next;
        else
          c=c->next;


        }

    a=a->next;
    }
cout<<"Not found";
return false;
}



/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* headA = NULL;
    struct node* headB = NULL;
    struct node* headC = NULL;

    /*create a linked list 'a' 10->15->5->20 */
    push (&headA, 20);
    push (&headA, 4);
    push (&headA, 15);
    push (&headA, 10);

    /*create a sorted linked list 'b' 2->4->9->10 */
    push (&headB, 10);
    push (&headB, 9);
    push (&headB, 4);
    push (&headB, 2);

    /*create another sorted linked list 'c' 8->4->2->1 */
    push (&headC, 1);
    push (&headC, 2);
    push (&headC, 4);
    push (&headC, 8);

    int givenNumber = 25;

    isSumSorted (headA, headB, headC, givenNumber);

    return 0;
}
