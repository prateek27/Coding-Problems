#include<iostream>
#include<cmath>
using namespace std;

class Node{
public:
int data;
int power;
Node*next;

public:
    Node(){
    data =0;
    power=0;
    }
    int getData() const{
        return data;
    }
    int getPower() const{
        return power;
    }
    void setData(int data){
        this->data = data;
    }
    void setPower(int power){
        this->power = power;
    }
    void setNext(Node* next){
        this->next = next;
    }
    Node*getNext(){
        return next;
    }
};

class Polynomial{
Node* head;
Node*tail;
int len;
        void equalisePolynomials(Polynomial &p2);
        void addEmptyNodesAtFront(Polynomial &p3,int count);

public:
        void createPolynomial();
        void PrintPolynomial();
        Polynomial operator+(Polynomial& p);
};

void Polynomial::createPolynomial(){
int data,power;int prev_power;
head = NULL;
tail = NULL;
cout<<"Enter coefficients and Power :"<<endl;
cin>>data>>power;
len=0;
while(data&&power){
    len++;

    if(head==NULL){
        Node *n = new Node;
        n->setData(data);
        n->setPower(power);
        head = tail = n ;
        prev_power = power;
        }
    else{
        prev_power -=1;
        while(prev_power!=power&&prev_power>0){
            len++;
            Node*n = new Node;
            n->setNext(NULL);
            n->setData(0);
            n->setPower(prev_power);
            prev_power--;
            tail->setNext(n) ;
            tail = tail->getNext();
        }
        Node*n = new Node;
        n->setData(data);
        n->setPower(power);
        n->setNext(NULL);
        tail->setNext(n);
        tail=tail->getNext();
     }

    cin>>data>>power;
    }

}
void Polynomial::PrintPolynomial(){
    struct Node*current = head;
    while(current!=NULL){
        cout<<current->getData()<<"x^"<<current->getPower()<<" + ";
        current = current->getNext();
    }
    cout<<"0x^0"<<endl;
}


void Polynomial::equalisePolynomials(Polynomial &p){
bool add1 = false;
add1 = this->len > p.len ? false:true;
int count = abs(this->len - p.len);
if(add1){
    while(count--){
        struct Node* n = new Node;
        n->setData(0);
        n->setPower(0);
        n->setNext(p.head);
        p.head = n;
        count--;
    }

}
else{

    while(count--){
        struct Node* n = new Node;
        n->setData(0);
        n->setPower(0);
        n->setNext(this->head);
        this->head = n;
        count--;

    }
}

return ;
}

Polynomial Polynomial::operator+(Polynomial &p2){
this->equalisePolynomials(p2);

Polynomial result;
struct Node*curr1 =  this->head;
struct Node*curr2 =  p2.head;


while(curr1&&curr2){
    curr1->setData(curr1->data+curr2->data);
    curr1 = curr1->getNext();
    curr2 = curr2->getNext();

    }

}



int main(){
Polynomial p1;
p1.createPolynomial();
p1.PrintPolynomial();
Polynomial p2;
p2.createPolynomial();
p2.PrintPolynomial();

p1.PrintPolynomial();

return 0;
}
