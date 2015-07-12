#include<iostream>
#include<unordered_map>
using namespace std;

//Author : Prateek Narang
// Time and Space Complexity : O(n)
// A more efficient solution exists which solves it in O(1) space and O(n) time . Takes 3 passes.See: Random Pointer Problem.cpp
struct node{
    int data;
    node*next;
    node*random;
    node(){
        data=0;
        next=NULL;
        random=NULL;
    }
    node(int v){
    data=v;
    next=NULL;
    random = NULL;
    }
};

typedef unordered_map<node*,node*> Map;

class LinkedList{

public:
    node*head;
    node*tail;

LinkedList(){
    head=NULL;
    tail=NULL;
}

void insert(int data){
    if(head==NULL){
        head = new node(data);
        tail = head;
    }
    else{
        tail->next = new node(data);
        tail = tail->next;
    }

}
void print(){
    struct node*temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void cloneUsingHashing(LinkedList &L2){
        Map m ;


        node*current = head;
        node*cloneCurrent;

        while(current!=NULL){
            cloneCurrent = new node(current->data);
            m.insert({current,cloneCurrent});

            //Mistake 1 : Setting the head of Second Linked List
            if(current==head)
                    L2.head=cloneCurrent;

            current = current->next;

            }

        current = head;

        while(current!=NULL){
            cloneCurrent = m[current];
            cloneCurrent->next = m[current->next];
            cloneCurrent->random = m[current->random];

            // Mistake 2 : Forget to move current to next positon.
            current=current->next;
            }

        return;
    }
};


int main(){
LinkedList L;

L.insert(1);
L.insert(2);
L.insert(3);
L.insert(4);
L.insert(5);



L.head->random = L.head->next->next;
L.head->next->random = L.head->next->next->next->next;

L.print();

cout<<L.head->random->data;
cout<<L.head->next->random->data;

LinkedList l2;
cout<<"Random exp "<<endl;

L.cloneUsingHashing(l2);
l2.print();
cout<<l2.head->random->data;
cout<<l2.head->next->random->data;


return 0;
}


