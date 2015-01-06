#include<iostream>
using namespace std;


class Node{
int obj;
Node*next;

public:
    Node(const int &obj){
        this->obj = obj;
    }
    int getObject(){
        return obj;
    }


    Node* getNext(){
        return next;
    }
    void setNext(Node*next){
        this->next = next;
    }
};



class LinkedList{
Node *head;
Node *tail;
int size;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertFront(const int &obj) {
        if(head == NULL){
            head = tail = new Node(obj);
        }
        else{
            Node *temp = new Node(obj);
            temp->setNext(head);
            head = temp;
        }
    }

    void insertBack(const int &obj){

            if(head == NULL){
            head = tail = new Node(obj);
            }
            else{
            tail->setNext(new Node(obj));
            tail = tail->getNext();
            }
        }

    friend ostream& operator<<(ostream out,LinkedList L);
};



int main(){
LinkedList L;
L.insertBack(1);
L.insertBack(2);
L.insertBack(3);
L.insertBack(4);
cout<<L;
}
