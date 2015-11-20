#include<vector>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<climits>
#include<set>
#include<fstream>
#include<cmath>
#include<bitset>
#include<map>
#include<iostream>
#include<queue>
#define test(t) while(t--)
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)

#define p(n) printf("%lld\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>
#define pb push_back
#define inf 1000000000LL
#define mp make_pair
#define MOD 1000000007LL

//#define inf 100000000
#define ll  long long
using namespace std;
ll a[100002];

int main()
{
int n,i,q,n1,n2,j,k,p;
s(n);s(k);
for(i=0;i<n;++i)
{
 sl(a[i]);
}
int f=0;
ll d1,a1;
d1=a1=INT_MAX;
if(n<=30)
{
for(i=0;i<n;++i)
{
  for(p=0;p<n;++p)
   {
      if(i==p)
      continue;
      int n1=max(p,i);
      int n2=min(p,i);
     ll diff=(a[n1]-a[n2])/(n1-n2);
     int f=0;
     if(diff*((ll)(n1-n2))==(a[n1]-a[n2]))
     f=1;
     if(f==1)
     {
     int ct=0;
       for(j=0;j<n;++j)
       {
        ll dist=a[j]-a[i];
        if(dist!=((j-i)*(diff)))
        ct++;
        if(ct>k)
        break;
       }
       if(ct<=k)
       {
         ll strt=a[i]-i*diff;
         if(strt<a1)
         {
           a1=strt;
           d1=diff;
         }
         else if(strt==a1 && (diff<d1))
         {
           d1=diff;
         }
       }
    }
  }
}
}
else
{
   vector<ll>v;
   for(i=1;i<n;++i)
   v.pb(a[i]-a[i-1]);
   sort(v.begin(),v.end());
   int maxdiff=-1;
   ll val;
   int tmp=1;
   for(i=1;i<v.size();++i)
   {
     if(v[i]==v[i-1])
     tmp++;
     else
     {
      if(tmp>maxdiff)
      {
       val=v[i-1];
       maxdiff=tmp;
       tmp=1;
      }
     }
   }
     if(tmp>maxdiff)
      {
       val=v[(int)v.size()-1];
       maxdiff=tmp;
       tmp=1;
      }
   int fin;
   for(i=1;i<n-1;++i)
   {
    if(((a[i]-a[i-1])==val) && ((a[i+1]-a[i])==val))
    {
     fin=i;
     break;
    }
   }
    a1=a[fin]-val*fin;
     d1=val;
}
for(j=0;j<n;++j)
 {
    ll dist=a1+j*d1;
   printf("%lld ",dist);
 }
return 0;
}
