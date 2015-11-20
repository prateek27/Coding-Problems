#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

int main(){
int a[] = {10,30,5,60};

priority_queue<int,vector<int>,greater<int> > pq(a,a+4);
while(!pq.empty()){
    int x = pq.top();
    cout<<x<<" ";
    pq.pop();
}

cout<<endl;
priority_queue<int> pq2(a,a+4);
while(!pq2.empty()){
    int x = pq2.top();
    cout<<x<<" ";
    pq2.pop();
}

return 0;
}
