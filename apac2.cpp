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
#include<stack>
#include<fstream>
#include<iostream>
#include<queue>
#include<assert.h>
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

#define N 100004
#define LN 20
#define ll long long
//#define inf 100000000
ll mod = 1e9 + 7;
using namespace std;
ll modExp(ll a,ll b,ll md){
    ll ans = 1;
    while(b){
       if(b&1)
            ans = (ans*a)%md;
        a = (a*a)%md;
        b/=2;
    }
    return ans;
}

ll inverse(ll num){
    if(num==0)
        return 1LL;
   return modExp(num,mod-2,mod);
}


int ene,n,m;
int hor[1001];
int hp[101],vp[101];

int possible(int ti){
    int av = ene;
     int i,j;
   for(i=0;i<n;++i){
       int poss = -1;
       int minm = m;
      for(j=0;j<m;++j){
         int ne = abs(vp[i]-j);
         if(ne>av)
            continue;
         if((hp[i]<0) && (hor[j]<=0))
            continue;
         if((hp[i]>0) && (hor[j]>=0))
            continue;
         int diff = abs(hp[i]);
         if(diff==0){
            minm = min(minm,ne);
            poss = 1;
         }else{

            int ve = abs(hor[j]);
            int tim = diff/ve;
            if(diff%ve!=0)
                tim++;
            if(tim<=ti){
               minm = min(minm,ne);
               poss = 1;
            }
         }
      }
      if(poss==-1)
        return 0;
      else
        av-=minm;
   }
   return 1;
}

int main(){

int i,j,n1,n2,t;
int test;
cin>>test;
for(t=1;t<=test;++t){
   cin>>n>>m>>ene;
   for(i=0;i<m;++i){
      cin>>hor[i];
   }
   for(i=0;i<n;++i){
      cin>>hp[i]>>vp[i];
   }
   cout<<"Case #"<<t<<": ";
   int lo = 0;
   int hi = 10000;
   int ans = -1;
   while(lo<=hi){
      int mi = (lo+hi)/2;
      if(possible(mi)){
        ans = mi;
        hi = mi -1;
      }else{
         lo = mi +1;
      }
   }
   if(ans!=-1)
    cout<<ans<<endl;
   else
        cout<<"IMPOSSIBLE\n";
}

}
