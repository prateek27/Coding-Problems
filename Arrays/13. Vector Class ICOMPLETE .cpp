#include<iostream>
using namespace std;

class Vector{
int top;
int *arr;
int size;

public:
    Vector();
    void push(int data);
    int pop();
};
Vector::Vector(){
size = 5;
top = 0;
int *arr = new int[size];
}

void Vector::push(int data){
    if(top==size-1){
        struct node*temp = arr;
        arr = new int[2*size];
        for(i=0;i<size;i++){
            ar[i++] =
        }
    }

}

int main(){

return 0;
}
