#include<iostream>
using namespace std;

int a[100];

int main(){
int n;
cout<<"Enter a Number for Fibonacci ";
cin>>n;
fib(n);
for(i=0;i<n;i++){
    cout<<a[i];
}
return 0;
}

int fib(int n){
if(n==0||n==1)
    return 1;
a[n-1]=fib(n-1)+fib(n-2);
return a[n-1];

}
