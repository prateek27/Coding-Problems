#include<iostream>
#include<stack>
using namespace std ;




void Push(stack<int> &s,stack<int> &sMin,int data)
{

    if(s.empty()&& sMin.empty())
        {
        s.push(data);
        sMin.push(data);
        }
    else{
    s.push(data);
    if(sMin.top()>=data)
            sMin.push(data);
    }
return;
}

void Pop(stack<int> &s , stack<int> &sMin){

    if(s.top()==sMin.top())
        {
            s.pop();
            sMin.pop();
        }
    else{
        s.pop();
    }
return ;
}

int findMin(stack<int> &s,stack<int> &sMin){
return sMin.top();
}


int main(){
stack<int> s,sMin;
Push(s,sMin,5);
Push(s,sMin,1);
cout<<findMin(s,sMin);
Push(s,sMin,-1);

Push(s,sMin,0);
cout<<findMin(s,sMin);

return 0;
}
