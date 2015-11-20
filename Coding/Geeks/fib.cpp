#include<iostream>
using namespace std;
//Fibnonacci using Recursion !!
int fib(int n){

if(n==1||n==0)
return 1;

return fib(n-1)+fib(n-2);

}



int main(){
int n;
cout<<"Enter n ";
cin>>n;
cout<<fib(n-1);


return 0;
}
