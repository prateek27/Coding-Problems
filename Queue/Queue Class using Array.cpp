#include<iostream>
using namespace std;

class Queue{
int currentSize;
int maxSize;
int front;
int rear ;
int *q;

public:
    Queue(int);
    void enqueue(int no);
    int dequeue();
    bool isEmpty()
    {
        return currentSize==0?true:false;
    };
};
Queue::Queue(int maxSize){
 q = new int[maxSize];
 this->maxSize = maxSize;
 front = 0;
 rear = -1;
 currentSize=0;
}

void Queue::enqueue(int x){

    if(currentSize==maxSize){
        cout<<"Queue is Full"<<endl;
        return;
    }
    if(rear ==maxSize)
        rear=0;

    rear++;
    q[rear]=x;
    currentSize++;
return;
}

int Queue::dequeue(){

if(currentSize==0)
{
    cout<<"Empty Queue";
    return -1;
}

int  ans = q[front];
front++;
currentSize--;

if(front==maxSize)
    front=0;

if(currentSize==0){
    front=0;
    rear = -1;
}

return ans;
}


void print(Queue q){
while(!q.isEmpty()){
    cout<<q.dequeue()<<" ";
    }

return ;
}

int main(){
Queue *q = new Queue(5);
q->enqueue(1);
q->enqueue(2);
q->enqueue(3);
q->enqueue(4);
q->enqueue(5);
q->enqueue(6);
q->enqueue(7);
print(*q);
return 0;
}
