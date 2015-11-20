#include<iostream>
#include<cstdio>
using namespace std;
#define mod 1000000007
long long dp[101];
long long ans,ans1;
long long rec(int n,int k)
{
 if(n==0)
 return 1;
 else if(dp[n]!=-1)
 return dp[n];
 else
 {
  int i;
  long long tmp;
  tmp=0LL;
  for(i=1;i<=min(n,k);++i)
  {
    tmp=tmp+rec(n-i,k);
    tmp=tmp%mod;
  }
  dp[n]=tmp;
  return dp[n];
 }
}
int main()
{

int n,k,d,i,j;
for(i=0;i<=100;++i)
{
dp[i]=-1;
}
ans=0LL;
cin>>n>>k>>d;
ans=rec(n,k);
for(i=0;i<=100;++i)
{
dp[i]=-1;
}
ans1=rec(n,d-1);
cout<<(ans-ans1+2*mod)%mod<<endl;
return 0;
}
