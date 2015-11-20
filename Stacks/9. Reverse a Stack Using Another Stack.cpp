#include<iostream>
#include "stack_using_node.h"
using namespace std;

//----------------------------------------Recursive Implementation
void insertAtBottom(stack_using_node<int> &s,int data){
   int temp;
   if(s.isEmpty()))
   {
       s.push(data);
   }
   else
   {
     int temp = s.pop();
     insertAtBottom(s,data);
     s.push(data);
   }
}


void reverseStack(stack_using_node<int> &s){
if(!s.isEmpty()){

        int top = s.pop();
        reverseStack(s);
        insertAtBottom(top);

    }
}
//----------------------------------------------Non Recursive Implemenation


int main(){
stack_using_node<int> s;
s.push(1);
s.push(2);
s.push(3);

reverseStack(s);

while(!s.isEmpty()){
    cout<<s.pop();
}
return 0;
}
