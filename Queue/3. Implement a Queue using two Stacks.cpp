#include<iostream>
#include<stack>
using namespace std ;
// TIME COMPLEXITY : Enqueue O(1) , Dequeue O(N) , Front O(N) in Worst case
class Queue{

stack<int> s1;
stack<int> s2;

public:
    void enQueue(int data);
    void deQueue();
    int front();
};
void Queue::enQueue(int data){
        s1.push(data);
}
void Queue::deQueue(){
    if(s1.empty()&&s2.empty())
        cout<<"No Elements in Queue "<<endl;
    else if(!s2.empty())
        { cout<<"Removing..."<<s2.top()<<endl;s2.pop();}
    else if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"Removing..."<<s2.top()<<endl;s2.pop();
    }
}
int Queue::front(){
    if(s1.empty()&&s2.empty())
        cout<<"No Elements in Queue "<<endl;
    else if(!s2.empty())
        { cout<<"Front..."<<s2.top()<<endl;
          return s2.top();
        }
    else if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        cout<<"Front..."<<s2.top()<<endl;
        return s2.top();
    }

}

int main(){
Queue Q;
Q.enQueue(1);
Q.enQueue(2);
Q.front();
Q.enQueue(3);
Q.deQueue();
Q.front();
Q.deQueue();
Q.front();
Q.deQueue();
Q.front();
return 0;
}
