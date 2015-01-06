#include<iostream>
using namespace std;


template<typename T>
class Node{
T obj;
Node*next;
public:
    Node(const T &obj){
        this->obj = obj;
    }
    T getObject(){
        return obj;
    }

    Node* getNext(){
        return next;
    }
    void setNext(Node*next){
        this->next = next;
    }
};


template<typename T>
class LinkedList{
Node<T>*head;
Node<T>*tail;
int size;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertFront(const T &obj) {
        if(head == NULL){
            head = tail = new Node<T>(obj);
        }
        else{
            Node<T>*temp = new Node<T>(obj);
            temp->next = head;
            head = temp;
        }
    }

    void insertBack(const T &obj){

            if(head == NULL){
            head = tail = new Node<T>(obj);
            }
            else{
            tail->next = new Node<T>(obj);
            tail = tail->next;
            }
        }

    friend ostream& operator<<(ostream out,LinkedList<T> L);

};


    template<typename T>
    ostream& operator<<(ostream out,LinkedList<T> L){
    while(L.head!=NULL){
        cout<<L.head->getObject().getData()<<" -> ";
        L.head = L.head->getNext();
    }
    cout<<endl;
    return out;
    }


class Person{
int data;
int marks;
public:
    Person(int a,int b){
        data = a;
        marks = b;
    }
    int getData(){
    return data;
    }
};

int main(){
LinkedList<Person> L;
Person p1(1,10);
Person p2(2,20);
Person p3(3,30);
Person p4(4,40);
Person p5(5,50);

cout<<L;
}
