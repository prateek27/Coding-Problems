#include<iostream>
using namespace std;
//Fibnonacci using Recursion !!

int main(){

int n,i;
cout<<"Enter n ";
cin>>n;
long long c,b=0,a=1;
for(i=1;i<=n;i++)
{
    c=b+a;
    a=b;
    b=c;

}
cout<<c;

return 0;
}
