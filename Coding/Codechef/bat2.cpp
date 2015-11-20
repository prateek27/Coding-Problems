#include<vector>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<climits>
#include<set>
#include<cmath>
#include<bitset>
#include<map>
#include<iostream>
#include<queue>
#define test(t) while(t--)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define min(a,b)(a<b?a:b)
#define p(n) printf("%d\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>
#define pb push_back
#define inf 1000000000LL
#define mp make_pair
#define mod 1000000007
//#define inf 100000000
#define ll  long long
#define gc getchar_unlocked
//long long m[2000005],n[2000005];
//ll dp[2005][2005];
using namespace std;
int n;
int a[102];
int dp[102][102][102];
int rec(int curr,int lisend,int ldsend)
{
	//cout<<curr<<" "<<lisend<<" "<<ldsend<<" "<<endl;
	if(curr==n)
	{
		return 0;
	}
	else if(dp[curr][lisend][ldsend]!=-1)
	{
		return dp[curr][lisend][ldsend];
	}
	else if(lisend==n && ldsend==n)
	{
		dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend)));
			return dp[curr][lisend][ldsend];
	}
	else if(lisend==n)
	{
		if(a[curr]<a[ldsend])
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend)));
			return dp[curr][lisend][ldsend];
		}
		else
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),rec(curr+1,lisend,ldsend));
			return dp[curr][lisend][ldsend];
		}
	}
	else if(ldsend==n)
	{
		if(a[curr]>a[lisend])
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend)));
			return dp[curr][lisend][ldsend];
		}
		else
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend));
			return dp[curr][lisend][ldsend];
		}
	}
	else
	{
		if(a[curr]>a[lisend] && a[curr]<a[ldsend])
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend)));
			return dp[curr][lisend][ldsend];
		}
		else if(a[curr]>a[lisend])
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,curr,ldsend),rec(curr+1,lisend,ldsend));
			return dp[curr][lisend][ldsend];
		}
		else if(a[curr]<a[ldsend])
		{
			dp[curr][lisend][ldsend]=max(1+rec(curr+1,lisend,curr),rec(curr+1,lisend,ldsend));
			return dp[curr][lisend][ldsend];
		}
		else
		{
			dp[curr][lisend][ldsend]=rec(curr+1,lisend,ldsend);
		return dp[curr][lisend][ldsend];
	     }
	}
}
int main()
{
	int t,i,j;

	s(t);
	while(t--)
	{

	   s(n);
	  for(i=0;i<n;++i)
	  {
	  	s(a[i]);
	  }
	  //memset(dp,0,sizeof(dp));
	   for(i=0;i<=n+1;++i)
	   {
	   	for(j=0;j<=n+1;++j)
	   	{
	   		for(int k=0;k<=n+1;++k)
	   		{
	   		dp[i][j][k]=-1;
	   		}
	   	}
	   }
	 p(rec(0,n,n));
	}
	return 0;
}
