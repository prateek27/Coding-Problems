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

struct bucket{
char color;
int position;
};

vector<bucket> v;

bool compare(const bucket&a,const bucket&b){
return a.position<b.position;
}
main(){
    int tc,i;
    si(tc);
    char color,prevColor;
    int index,prevIndex;


    while(tc--){
    int n,m;
    si(n);
    si(m);
    v.clear();

    ll ans=1;


    FOR(i,0,m){
    scanf(" %c%lld",&color,&index);
//    cin>>color;
  //  cin>>index;
    struct bucket b1;
    b1.color=color;
    b1.position=index;
    v.push_back(b1);
    }

    sort(v.begin(),v.end(),compare);

    prevColor = v[0].color;
    prevIndex = v[0].position;

    FOR(i,1,m){
    char col = v[i].color;
    int idx = v[i].position;

    if(col!=prevColor){
        ans = ans*(idx-prevIndex);
        ans%=MOD;
    }
    prevColor=col;
    prevIndex=idx;
    }
    printl(ans);
}
return 0;
}
