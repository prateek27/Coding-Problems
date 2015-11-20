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
#define s(n) scanf("%lld",&n)
#define sl(n) scanf("%d",&n)
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
ll abso(ll a)
{
	if(a>0LL)
	return a;
	else
	return a*(-1LL);
}
int main()
{
	ll t,n,i,j,tt;
	 ll a[21][21];
	ll dp[21][21];
	ll time[21][21];
	s(t);
	while(t--)
	{
		s(n);s(tt);
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				s(a[i][j]);
				dp[i][j]=0LL;
				time[i][j]=0LL;
			}
		}
		time[n-1][n-1]=0;
		dp[n-1][n-1]=0;
		j=n-1;
		for(i=n-2;i>=0;--i)
		{
			if(a[i+1][j]>a[i][j])
			{
			dp[i][j]=max(dp[i+1][j],a[i+1][j]-a[i][j]);
			}
			else
			{
				dp[i][j]=dp[i+1][j];
			}
			time[i][j]=time[i+1][j]+abso(a[i+1][j]-a[i][j]);
		}
		i=n-1;
		for(j=n-2;j>=0;--j)
		{
			if(a[i][j+1]>a[i][j])
			{
				dp[i][j]=max(dp[i][j+1],a[i][j+1]-a[i][j]);
			}
			else
			{
				dp[i][j]=dp[i][j+1];
			}
			time[i][j]=time[i][j+1]+abso(a[i][j+1]-a[i][j]);
		}
		for(i=n-2;i>=0;--i)
		{
			for(j=n-2;j>=0;--j)
			{
				ll tmp1,tmp2;
				if(a[i+1][j]>a[i][j])
				{
					tmp1=max(dp[i+1][j],a[i+1][j]-a[i][j]);
				}
				else
				tmp1=dp[i+1][j];
				if(a[i][j+1]>a[i][j])
				{
					tmp2=max(dp[i][j+1],a[i][j+1]-a[i][j]);
				}
				else
				tmp2=dp[i][j+1];
				if(tmp1<tmp2)
				{
					dp[i][j]=tmp1;
					time[i][j]=time[i+1][j]+abso(a[i+1][j]-a[i][j]);
				}
				else if(tmp1>tmp2)
				{
					dp[i][j]=tmp2;
					time[i][j]=time[i][j+1]+abso(a[i][j+1]-a[i][j]);
				}
				else
				{
					ll tmp3,tmp4;
					tmp3=time[i+1][j]+abso(a[i+1][j]-a[i][j]);
					tmp4=time[i][j+1]+abso(a[i][j+1]-a[i][j]);
					if(tmp3<=tmp4)
					{
						dp[i][j]=tmp1;
					    time[i][j]=tmp3;
					}
					else
					{
						dp[i][j]=tmp2;
					    time[i][j]=tmp4;
					}
				}
			}
		}
	/*	for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
			cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
			cout<<time[i][j]<<" ";
			}
			cout<<endl;
		}*/
	   if(time[0][0]+a[0][0]>tt)
	   {
	   	cout<<"NO\n";
		}
	   	else
	   	{
	   		cout<<"YES : "<<max(dp[0][0],a[0][0])<<" "<<tt-(time[0][0]+a[0][0])<<endl;
	   	}
	   }
	return 0;
}

