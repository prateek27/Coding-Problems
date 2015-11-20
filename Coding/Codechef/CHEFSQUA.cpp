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
#define si(n) scanf("%llu",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000009
#define printl(n) printf("%llu\n",n);
#define ll long long
#include<vector>
#define vii vector<pair<int,int> >
#define int long long unsigned
#define pii pair<int,int>
#include<bitset>

map<pii,char> myMap;
vector<pair<int,int> > v;
main(){
int n,i,x,y,j;
si(n);
//n=fcin();
FOR(i,0,n){
si(x); si(y);
//x = fcin(); y = fcin();
pii p = make_pair(x,y);
v.push_back(p);
myMap[p]='a';
}


int ans;

if(n==0)
    ans=4;
else if(n==1)
    ans=3;
else if(n==2)
    ans=2;
else{
     ans = 4;
     FOR(i,0,n-1)
     {
         float xb,yb,xt,yt;
         FOR(j,i+1,n)
            {

             float x1 = v[i].first;
             float y1 = v[i].second;
             float x2 = v[j].first;
             float y2 = v[j].second;

  float xc,xd,yc,yd,x3,x4,y3,y4;
  xc = (x1 + x2)/2  ;
  yc = (y1 + y2)/2  ;
  xd = (x1 - x2)/2  ;
  yd = (y1 - y2)/2  ;

  x3 = xc - yd ;  // Third corner
  y3 = yc + xd;
  x4 = xc + yd ;  // Fourth corner
  y4 = yc - xd;

    int required=2;

     if((x3-(int)x3)==0.0&&(y3-(int)y3)==0.0&&myMap.count(make_pair(x3,y3))>0)
        required--;
     if((x4-(int)x4)==0.0&&(y4-(int)y4)==0.0&&myMap.count(make_pair(x4,y4))>0)
        required--;
     ans = min(ans,required);

        }
    }
}
printf("%d",ans);

return 0;
}
