#include<iostream>
#include<math.h>
using namespace std;
#define int long long

int count_div(int n){
int i,count=0,ans=1;

while(n%2==0)
{
     n=n>>1;
     count++;
}

ans=ans*(count+1);
count=0;
for(i=3;i<=sqrt(n);i+=2)
{
while(n%i==0) { count++; n=n/i; }
ans=ans*(count+1);
count=0;
}
if(n>2)
    ans=ans*2;

return ans;
}

int isPrime(int n)
{
    if(n>2&&n%2==0) return 0;
    for(int i=3;i<=sqrt(n);i+=2)
    {

     if(n%i==0) return 0;
    }


return 1;
}

main(){
int t,l,r,var=0;
cin>>t;
while(t--){
    cin>>l>>r;
    for(int j=l;j<=r;j++){


     if(isPrime(count_div(j))) { cout<<j<< " and no divisor "<<count_div(j)<<endl; var++ ;}
    }
   if(l==1)
   cout<<var-1;
   else
    cout<<var;
   var=0;
}


return 0;
}
