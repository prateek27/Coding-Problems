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
//-----------------------Queue Class Implementation

class Queue{
struct node*head;
struct node*tail;

public:
    Queue(){
    head = tail = NULL;
    }
    void enQueue(int data);
    void deQueue();
    int  front();

};
void Queue::enQueue(int data){
    if(head==NULL){
        head=tail=newNode(data);
    }
    else{
        tail->next = newNode(data);
        tail=tail->next;
    }
}
void Queue::deQueue(){
    if(head!=NULL)
        {
        struct node*temp = head;
        head = head->next;
        delete temp;
        }
    else{
    cout<<"Queue is empty!";
    }
}
int Queue::front(){
if(head!=NULL)
    return head->data;
else{
cout<<"Empty Queue";
return -1;
    }
}

int main(){

Queue q;
q.enQueue(1);
q.enQueue(2);
q.enQueue(3);
cout<<q.front()<<endl;
q.deQueue();
q.deQueue();
cout<<q.front()<<endl;
q.deQueue();
cout<<q.front()<<endl;

return 0;
}
