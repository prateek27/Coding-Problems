#include<iostream>
using namespace std;

struct Queue{
    int arr[100];
    int front;
    int rear;
    int currentSize;
};


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


void print(Queue Q){

while(Q.currentSize){
    cout<<Q.arr[Q.front]<<" ";
    deQueue(Q);
    }
    cout<<endl;
}


int main(){
Queue Q ;
Q.front = 0;
Q.rear = -1;
enQueue(Q,1);
enQueue(Q,2);
enQueue(Q,3);
deQueue(Q);
enQueue(Q,5);
print(Q);
}
