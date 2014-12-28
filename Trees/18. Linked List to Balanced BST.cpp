#include<iostream>
using namespace std;
// Note: take a sorted  linked list
// Lil Buggy Code
struct node{
int data;
struct node*next;
struct node*prev;
};
struct node*newNode(int data){
struct node*node = new struct node;
node->data = data;
node->next = NULL;
node->prev = NULL;
return node;
}

void insertDLL(struct node**head,int data){
    if(*head==NULL){
        *head = newNode(data);
    }
    else {
        struct node*temp = newNode(data);
        temp->next = (*head);
        (*head)->prev = temp;
        *head = temp;
    }
return;
}
void printDLL(struct node*head){
    while(head!=NULL){
        cout<<head->data<<" <=> ";
        head = head->next;
    }
cout<<endl;
}

struct node* linkedListToBST(struct node**root){

if(*root==NULL){
    return NULL;
}

struct node*fast = *root;
struct node*slow = *root;
struct node*prev;



while(fast!=NULL){
    fast = fast->next;
    if(fast!=NULL)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
    }
prev->next = NULL;  //Break The links
slow->prev = NULL ;

struct node* prevPrev = prev->prev;
prev->prev = NULL;
prevPrev->next = NULL;

cout<<prev->data<<endl;
printDLL(*root);
printDLL(slow);

prev->prev = linkedListToBST(root);
prev->next = linkedListToBST(&slow);
return prev;
}


int main(){
struct node*root = NULL;
insertDLL(&root,8);
insertDLL(&root,7);
insertDLL(&root,6);
/*insertDLL(&root,5);
insertDLL(&root,4);
insertDLL(&root,3);
insertDLL(&root,2);
insertDLL(&root,1);*/
printDLL(root);
linkedListToBST(&root);
return 0;
}
