#include<iostream>
using namespace std;

int main(){
long long t, n,m,num,o;
long long sum=0;
cin>>t;
while(t--){
cin>>num;
if(num%3==0) n=(num/3)-1;
else n=num/3;

if(num%5==0) m=(num/5)-1;
else m=num/5;

if(num%15==0) o=(num/15)-1;
else o=num/15;


sum=sum + 3*n*(n+1)/2+ 5*m*(m+1)/2 - 15*o*(o+1)/2;

   cout<<sum<<endl;

sum=0;
}




return 0;
}
