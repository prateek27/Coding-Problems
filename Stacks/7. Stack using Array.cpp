#include<iostream>
using namespace std;
#define SIZE 100

class Stack{
int *arr;
int top_index;
int max_size;
public:
     Stack(int cap){
     max_size = cap;
     arr = new int[max_size];
     top_index = -1 ;
     }

     void push(int data);
     void pop();
     int top();

};

void Stack::push(int data)
{
    if(top_index==max_size-1){
    cout<<"Stack Full"<<endl;
    return;
    }
    else{
        arr[++top_index]=data;
    }
}

void Stack::pop(){
if(top_index!=-1){
    top_index--;
}
else{
    cout<<"Stack Empty";
}
}

int Stack::top(){
    if(top_index!=-1)
        return arr[top_index];
}

int main(){
Stack s(3);  //Capacity
s.push(1);
s.push(2);
s.push(3);
s.push(4);
cout<<s.top();
s.pop();
s.pop();
cout<<s.top();
return 0;
}
