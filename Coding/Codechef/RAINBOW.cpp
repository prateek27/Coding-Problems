#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[1000005];

ll preCompute(int n){

memset(dp,0,n);

dp[13]=1;
int i,j;

for(i=15;i<=n;i+=2)
{  dp[i]= dp[i-2]*7;
   dp[i]%=MOD;
}
return dp[n];
}

int main(){
int n;
scanf("%d",&n);
if(n&1)
printf("%lld\n",preCompute(n));
else
printf("%lld\n",preCompute(n));

return 0;
}
