#include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node*next;

    Node():next(NULL),data(0){}
    Node(int d):data(d),next(NULL){}
};

class LinkedList{
public:
    Node*head;
    Node*tail;
    int len;
    LinkedList():head(NULL),tail(NULL),len(0){

    }
    void insertAtEnd(int data){
        len++;
        if(head==NULL){
            head = new Node(data);
            tail = head;
        }
        else{
            tail->next = new Node(data);
            tail = tail->next;
        }

    }
    friend ostream& operator<<(ostream &os,LinkedList &ll){
        Node*temp = ll.head;
        while(temp){
            os<<temp->data<<" -->";
            temp = temp->next;
        }
        os<<endl;
    return os;
    }


    ~LinkedList(){
        //Clear all the memory by deleting nodes.
    }

};


LinkedList add(const LinkedList &la,const LinkedList &lb){

LinkedList c;

Node*a = la.head;

Node*b = lb.head;

int len = la.len;
//This creates a empty c linked list of n+1 nodes.
for(int i=0;i<=len;len++){
 c.insertAtEnd(0);
}
Node*cslow = c.head;
Node*cfast = c.head->next;

while(a->next && b->next){
    int current_sum = a->data + b->data;

    if(current_sum <= 8 ){
        cfast->data = current_sum;
        cslow = cfast;
        cfast = cfast->next;
        a = a->next;
        b = b->next;
    }
    else if(current_sum==9){
        cfast->data = 9;
        cfast = cfast->next;
        a = a->next;
        b = b->next;
    }
    else{
        // >10
        while(cslow!=cfast){
            cslow->data += 1;
            cslow = cslow->next;
        }
        cfast->data = current_sum%10;
        cfast = cfast->next;
        a = a->next;
        b = b->next;
    }

}



}


int main(){
LinkedList ll;
ll.insertAtEnd(4);
ll.insertAtEnd(9);
ll.insertAtEnd(8);
ll.insertAtEnd(3);

LinkedList ll2;
ll2.insertAtEnd(5);
ll2.insertAtEnd(6);
ll2.insertAtEnd(1);
ll2.insertAtEnd(9);

cout<<ll<<ll2;
LinkedList l3 = add(ll,ll2);
cout<<l3;
return 0;
}
