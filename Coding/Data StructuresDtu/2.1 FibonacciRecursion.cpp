#include<iostream>
using namespace std;

//Fibonacci Using recursion

int fib(int n){
if(n==1||n==0)
return 1;
return fib(n-2)+fib(n-1);

}
int main(){
int n;
cin>>n;
cout<<fib(n);
return 0;
}

