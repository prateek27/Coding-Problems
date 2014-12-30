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
//-------------------------------------------Selection Sort
struct node* findMinANdRemove(struct node** start)
{
    struct node* current = *start;
    struct node* min = current;
    struct node* prev = NULL;

    while (current->next != NULL)
    {
        if ( (current->next)->data < min->data )
        {
            prev = current;
            min = current->next;
        }

        current = current->next;
    }

    if (prev == NULL)
    {
        *start = min->next;
        return min;
    }
    else
    {
        prev->next = prev->next->next;
        return min;
    }
}

void selectionSort(struct node** headRef)
{
    struct node* min = NULL;
    struct node* current = *headRef;
    struct node* prev = NULL;

    while (current->next != NULL)
    {
        if (current == *headRef)
        {
            min = findMinANdRemove(headRef);
            *headRef = min;
            min->next = current;
            prev = *headRef;
        }

        else
        {
            min = findMinANdRemove(&current);
            prev->next = min;
            min->next = current;
            prev = prev->next;
        }
    }
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
