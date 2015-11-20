#include<iostream>
using namespace std;

int a[100];

int fib(int);
int main(){
int n;
cout<<"Enter a Number for Fibonacci ";
cin>>n;
fib(n);
a[0]=1;a[1]=1;
for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
}
return 0;
}

int fib(int n){
    a[0]=1;a[1]=1;
if(n==0||n==1)
    return a[1];
a[n]=fib(n-1)+fib(n-2);
return a[n];

}
