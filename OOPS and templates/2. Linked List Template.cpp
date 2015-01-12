#include<iostream>
using namespace std;


template<typename T>
class Node{
public:
T obj;
Node*next;

    Node(const T &ob): obj(ob){
        //this->obj = obj;
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


    friend ostream& operator<<(ostream &out,LinkedList<T> &L) {
    while(L.head!=NULL){
        cout<<L.head->getObject().getData()<<" -> ";
        L.head = L.head->getNext();
    }
    cout<<endl;
    return out;
    }

};


    /*template<typename T>
    friend ostream& operator<<(ostream &out, LinkedList<T> &L){

    }*/




int main(){
LinkedList<Person> L;
Person p1(1,10);
Person p2(2,20);
Person p3(3,30);
Person p4(4,40);
Person p5(5,50);
L.insertBack(p1);
L.insertBack(p2);
L.insertBack(p3);
L.insertBack(p4);
L.insertBack(p5);
L.insertBack(p5);
LinkedList<int> A;
A.insertBack(5);
A.insertBack(6);
//cout<<A;
cout<<L;
}
