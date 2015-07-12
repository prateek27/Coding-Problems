#include<iostream>
#include<stack>
using namespace std;

void findSpan(int *price,int n,int *span){
    stack<int> s;

    span[0]=1;
    s.push(0);

    for(int i=1;i<n;i++){
        while(!s.empty()&&price[i]>price[s.top()])
            s.pop();

    span[i]=s.empty()?i+1:(i-s.top());
    s.push(i);
    }


return;
}
void printArray(int *S,int n){
    for(int i=0;i<n;i++)
        cout<<S[i]<<" ";
}


int main(){
  int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];

    // Fill the span values in array S[]
  findSpan(price, n, S);

    // print the calculated span values
    printArray(S, n);

    return 0;

}
