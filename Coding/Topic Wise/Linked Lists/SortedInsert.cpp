#include<iostream>
using namespace std;
// Create a list in descending order .

//-------------------------------------------------------------Node Structure
struct node{
int data;
struct node*next;
};
struct node*head=NULL;
//--------------------------------------------------------------New Node
struct node*newNode(int data){
struct node*node=new struct node;
node->data=data;
node->next=NULL;
return node;
};
//--------------------------------------------------------------Sorted Insert
void sortedInsert(struct node**headRef,int data){
struct node*current =*headRef;

if(*headRef==NULL)
{
*headRef=newNode(data);
}

else if(data>(*headRef)->data) {
struct node*temp=newNode(data);
temp->next=*headRef;
*headRef=temp;
}

else{
current = *headRef;
while (current->next!=NULL && current->next->data>data) {
current = current->next;
}


        struct node*temp=newNode(data);
            temp->next=current->next;
            current->next=temp;
    }
}
//---------------------------------------Print
void print(struct node*head){
struct node*node=head;
while(node!=NULL)
    {
    cout<<node->data<<" -> ";
    node=node->next;
    }
    cout<<"NULL";
}
//-------------------------------------Main
int main(){
/*sortedInsert(&head,5);
sortedInsert(&head,6);
sortedInsert(&head,3);
sortedInsert(&head,1);
sortedInsert(&head,2);
print(head);
*/
cout<<"Enter the elements .Press -1 to end ";
int n;
while(1){
    cin>>n;
    if(n==-1) break;
    sortedInsert(&head,n);
    print(head);
    cout<<endl;
    }
return 0;
}
