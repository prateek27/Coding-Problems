#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
//This function just returns the minimum in the window 0 to k
int findMinimum(int k,int n)
{ int min = 100000;
for(int i=0;i<n;i++){
    int current =  q.front();
    q.pop();
    if(current <min && i < k){
        min = current;
    }
    q.push(current);
    }
    return min;
}
//This places the minimum value at correct position
void reorder(int min,int n){
for(int i=0;i<n;i++){
    int current = q.front();
    q.pop();
    if(current!=min){
        q.push(current);
    }
}
q.push(min);
}



void sort(){
    int n = q.size();

for(int i=0;i<n;i++){
    int min = findMinimum(n-i,n);
  //cout<<min<<endl;
    reorder(min,n);
    }
}


int main(){
q.push(5);
q.push(4);
q.push(8);
q.push(2);
q.push(1);
q.push(9);
sort();
while(!q.empty()){
cout<<q.front()<<" ";
q.pop();
}
return 0;
}

