#include<iostream>
#include<math.h>
using namespace std;
#define MOD 1000000007
long long int pow(long long int b)
{
   long long int a=2;
   long long int ans=1;
    while(b!=0){
    if(b&1)
        ans=ans*a%MOD;

    b=b>>1;
    a=a*a%MOD;
    }
    return ans;
}

int main()
{
long long int n,t;
cin>>t;
while(t--)
{   cin>>n;
    cout<<(pow(n)-1)%MOD<<endl;
}
return 0;
}
