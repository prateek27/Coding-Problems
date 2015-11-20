#include<iostream>
using namespace std;

class List{
protected:
    struct node{
    int info;
    struct node*next;
    };
typedef struct node*NODEPTR;
NODEPTR head;

public:
    List();
    ~List();
    int emptyList();
    void insert_after(int key,int data);
    void push(int data);
    int pop();
};

List::List(){ head=NULL;}
List::~List(){ NODEPTR p,q;
    if(emptylist()) return 0;
    for(p=head;q=p->next;p!=NULL;p=q;q=p->next)
    delete p;
}

int List::emptylist(){ return head==NULL ;}

