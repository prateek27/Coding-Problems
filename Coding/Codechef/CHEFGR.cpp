#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MAX 110
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000007
#define printl(n) ("%lld\n",n);
#define ll long long

int r[105],b[105],g[105];

int maxOfThree(int a,int b,int c){
if(a>b)
    return a>c?1:3;

else
    return b>c?2:3;
}
void divideByTwo(int a[],int n){
int i ;
FOR(i,0,n)
    a[i] = a[i]>>1;
}

int main(){
int tc;
si(tc);
while(tc--){
    int R,G,B,M,i;
    si(R);si(G);si(B);si(M);

    int rsum=0,bsum=0,gsum=0;
    int rmax,gmax,bmax;


    FOR(i,0,R)
        {si(r[i]);}
    FOR(i,0,G)
        {si(g[i]);}
    FOR(i,0,B)
        {si(b[i]);}

    while(M--){
    rmax=gmax=bmax=-1;
    FOR(i,0,R)
        rmax=max(rmax,r[i]);
    FOR(i,0,G)
        gmax=max(gmax,g[i]);
    FOR(i,0,B)
        bmax=max(bmax,b[i]);

    int cmax = maxOfThree(rmax,gmax,bmax);
    cout<<"CMAX"<<cmax<<endl;
    switch(cmax){
    case 1:FOR(i,0,R) r[i]=r[i]/2; break;
    case 2:FOR(i,0,G) g[i]=g[i]/2; break;
    case 3:FOR(i,0,B) b[i]=b[i]/2; break;
    }
   // 1800266121
   // 9212092059
    }
    rmax=gmax=bmax=-1;
    FOR(i,0,R)
        rmax=max(rmax,r[i]);
    FOR(i,0,G)
        gmax=max(gmax,g[i]);
    FOR(i,0,B)
        bmax=max(bmax,b[i]);
    cout<<max(rmax,max(gmax,bmax))<<endl;
}

return 0;
}
