#include<iostream>
#include<cstring>
using namespace std;


/*
  Time Complexity : Push (O(1)) , Pop : (O(n))
*/
//-------------------------------------------Queue Implementation Works Fine

struct Queue{
    int arr[100];
    int front ;
    int rear ;
    int currentSize;
};

//--------------------------------Queue : EnQueue pushes the element at rear
void enQueue(Queue &Q,int x){

    Q.rear += 1;   //Bhaga Lo Pehle

    if(Q.currentSize==100){
        cout<<"Q is Full "<<endl;
        return ;
    }

    if(Q.rear == 100)
        Q.rear =0;

    Q.arr[Q.rear]=x;
    Q.currentSize++;
}
//-------------------------------Queue : Removes the element From the front
void deQueue(Queue &Q){
    if(Q.currentSize==0){
        cout<<"Empty "<<endl;
        return ;
    }
    Q.front++;
    if(Q.front==100){
     Q.front = 0;
    }
    Q.currentSize--;
    if(Q.currentSize==0){
        Q.front = 0;
        Q.rear = -1;
    }
}
//---------------------------------Queue : IsEmpty return true if Q is empty
bool isEmpty(Queue Q){
return Q.currentSize==0?true:false;
}

//---------------------------------------Stack Class Implementation Using Queues
class Stack{

    Queue q1;
    Queue q2;
    //Stack Constructor , Must Initialise Q members
public:
    Stack(){
     q1.rear = -1 ; q2.rear=-1;
     q1.front = 0; q2.front =0;
     q1.currentSize = 0 ; q2.currentSize = 0;
     memset(q1.arr,0,sizeof(q1.arr));
     memset(q2.arr,0,sizeof(q2.arr));
    }

    void push(int data);
    void pop();
    int top();
    bool isStackEmpty();

};
//------------------------------Stack : Push Function O(1) , Enqueue the 'non-empty' Queue
void Stack::push(int data){

cout<<"Pushed... "<<data<<endl;
if(isEmpty(q1)&&isEmpty(q2))
    {enQueue(q1,data);}
else if(!isEmpty(q1))
    enQueue(q1,data);
else if(!isEmpty(q2))
    enQueue(q2,data);

}
//-----------------------------Stack : Pop Function O(n) , Dequeue N-1 elements and Enqueue them in other Queue.Deque the last element
void Stack::pop(){
    //cout<<q1.currentSize;
    if(isEmpty(q1)&&isEmpty(q2)){
        cout<<"Can't pop from Empty Stack";
    }

    if(!isEmpty(q1)){

        while(q1.currentSize>1)
            {
            int temp = q1.arr[q1.front];
            deQueue(q1);

            enQueue(q2,temp);
            }
            int temp = q1.arr[q1.front];
            cout<<"Popped..."<<temp<<endl;
            deQueue(q1);
    }

    else if(!isEmpty(q2)){
        while(q2.currentSize>1)
           {
            int temp = q2.arr[q2.front];
            deQueue(q2);
            enQueue(q1,temp);
            }

            int temp = q2.arr[q2.front];
            cout<<"Popped..."<<temp<<endl;
            deQueue(q2);
    }
}
//----------------------------------------------Stack :Top() return the stack top , work like pop
int Stack::top(){
    if(isEmpty(q1)&&isEmpty(q2)){
    cout<<"Top Doesn't Exist";
    return -1;
    }
    else if(!isEmpty(q1)){
        while(q1.currentSize>1)
            {int temp = q1.arr[q1.front];
            deQueue(q1);
            enQueue(q2,temp);
            }
            int top = q1.arr[q1.front];
            deQueue(q1);
            enQueue(q2,top);
            return top;
    }

    else if(!isEmpty(q2)){
        while(q2.currentSize>1)
           { int temp = q2.arr[q2.front];
            deQueue(q2);
            enQueue(q1,temp);
            }
            deQueue(q2);
            int top = q2.arr[q2.front];
            deQueue(q2);
            enQueue(q1,top);
            return top;
        }

    }

//--------------------------------------------Stack : Return true if both queues are empty
bool Stack::isStackEmpty(){
    return isEmpty(q1)&&isEmpty(q2);
}
//---------------------------------------The Main Function
int main(){
Stack s;
cout<<"Top :"<<s.top()<<endl;
s.push(10);
cout<<"Top :"<<s.top()<<endl;
s.push(20);
s.push(30);
s.pop();
s.push(40);
cout<<"Top :"<<s.top()<<endl;
s.pop();
cout<<"Top :"<<s.top()<<endl;
s.pop();
cout<<"Top :"<<s.top()<<endl;
s.pop();
cout<<"Top :"<<s.top()<<endl;
return 0;
}



