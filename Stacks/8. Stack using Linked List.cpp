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

//-----------------------Stack Class Implementation using LL
class Stack{
struct node*head;
public:
    Stack(){
    head=NULL;
    }
void push(int data);
void pop();
int top();
};

void Stack::push(int data){
if(head==NULL){
        head = newNode(data);
    }
    else{
    struct node*node = newNode(data);
    node->next = head;
    head = node;
    }
}
void Stack::pop(){
if(head==NULL){
    cout<<"Stack Is Empty";
    }
    else{
    struct node*node = head;
    head = (head)->next;
    delete node;
    }
}
int Stack::top(){
if(head==NULL){
    cout<<"Stack Is Empty";
        return -1;
    }
    else{
        return head->data;
    }
}

int main(){
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
cout<<s.top()<<endl;
s.pop();
s.pop();
cout<<s.top()<<endl;
s.pop();
s.pop();
cout<<s.top()<<endl;
s.push(100);
cout<<s.top()<<endl;
}
