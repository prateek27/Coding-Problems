#include<iostream>
using namespace std;
//Fibnonacci using Recursion !!

int main(){

int n,i;
cout<<"Enter n ";
cin>>n;
long long fib[n+1];
fib[0]=fib[1]=1;
for(i=2;i<=n;i++)
{
    fib[i]=fib[i-1]+fib[i-2];
}
cout<<fib[n-1];

return 0;
}
