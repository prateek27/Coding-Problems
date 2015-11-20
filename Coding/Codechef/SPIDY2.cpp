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

bool compare(const pair<int,int> &a,const pair<int,int> &b){
return a.first<b.first;
}
#define pii pair<int,int>
#define vii vector<pii >

vii v,nv;

int cameras[100005];

bool binSearch(int val,int low,int high){


    while(low<=high){
        int mid = (low+high)/2;

        if(val>=v[mid].first&&val<=v[mid].second)
            return true;
        else if(val>v[mid].second&&val<v[mid+1].first)
            return false;
        else if(val>v[mid].first&&val>v[mid].second)
            low=mid+1;
        else
            high = mid-1;
            }
return false;
}
int main(){
int n,k,j;
cin>>n;
cin>>k;

FOR(j,0,n)
{ si(cameras[j]);}

int x,y;
FOR(j,0,k){
si(x); si(y);
pair<int,int> p = make_pair(x,y);
v.push_back(p);
}

sort(v.begin(),v.end(),compare);
vii::iterator i;
/*
nv.push_back(v[0]);

for(i=v.begin()+1;i!=v.end();i++)
{
    pii prev = nv.back();
    nv.pop_back();
    int pFirst = prev.first;
    int pSec   = prev.second;

    int first = (*i).first;
    int sec   = (*i).second;

    if(first<=pSec){
        sec<=pSec;
        nv.push_back(make_pair(pFirst,sec));
    }
    else{
        nv.push_back(prev);
        nv.push_back(*i);
        }
}
v.clear();
*/

int ans=0;
FOR(j,0,n)
{ int current = cameras[j];
  int len = v.size();
  if(binSearch(current,0,len-1))
    ans++;
}
cout<<ans<<endl;

return 0;
}
