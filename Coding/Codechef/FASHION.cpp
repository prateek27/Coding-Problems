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
#define printl(n) printf("%lld\n",n);
#define ll long long

int a[1005],g[1005];

int main(){
int tc;
si(tc);
while(tc--){

    int n,i;

    si(n);
    bool one=false;
    int idx=0;
    FOR(i,0,n)
        {
            int num;
            si(num);
            if(num==1)
                {one=true; continue;}
            a[idx++]=num;
        }

    sort(a,a+idx);
    if(one)
        cout<<"1 ";

    if(a[0]==2&&a[1]==3&&idx==2)
        cout<<"2 "<<"3 ";

    else{
        RFOR(i,idx,0)
            cout<<a[i]<<" ";
        cout<<endl;
    }

//    printf("%lld\n",ans);
}

return 0;
}
