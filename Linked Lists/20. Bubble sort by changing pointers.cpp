#include<iostream>
using namespace std;

// BUGGY CODE
//Finding it hard to implement . Will do later.
//For now data is being swapped like array.




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
//-----------------------------------Bubble Sort
void swap(struct node**head,struct node*a,struct node*b,struct node*c){
    if(a==NULL){
        struct node*cnext = c->next;
        *head = c;
        c->next = a;
        a->next = cnext;
    }
    else{
        struct node*cnext = c->next;
        a->next = c;
        c->next = b;
        b->next = cnext;

    }
return ;
}


void bubbleSort(struct node**head){
    int i;
    bool swapped = false;
    struct node*current=*head;
    struct node*rightEnd=NULL;
    struct node*prev = NULL;

    if(current==NULL)
        return ;
    do{
        swapped = false;
        current = (*head);

        while(current->next!=rightEnd){

          if(current->data>current->next->data){
            swap(head,prev,current,current->next);
            swapped = true;
        }
        prev = current;
        current = current->next;
        }
        rightEnd = current;
    }
    while(swapped);
    //When they are no swapping in the list means the list is sorted .
    // It will run in O(n) if the list is already sorted
return ;
}

int main(){
struct node*head = NULL;
pushFront(&head,1);
pushFront(&head,5);
pushFront(&head,3);
pushFront(&head,2);
pushFront(&head,0);
print(head);
bubbleSort(&head);
cout<<"After Bubble sort :"<<endl;
print(head);
return 0;
}



