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
#define si(n) scanf("%lld",&n);
#define sl(n) scanf("%lld",&n);
#define MOD 1000000007
#define printl(n) ("%lld\n",n);
#define ll long long
#include<vector>
#define vii vector<pair<int,int> >
#define int long long

vii dino;
vii ppl;

main(){
int tc;
si(tc);
while(tc--){
    int n,i,val;
    dino.clear();
    ppl.clear();
    si(n);

    FOR(i,0,n){
    si(val);
    if(val<0)
        dino.push_back(make_pair(-1*val,i));
    else
        ppl.push_back(make_pair(val,i));
    }

    vii :: iterator itr1 = dino.begin();
    vii :: iterator itr2 = ppl.begin() ;
    int cost = 0;
    while(1){

        if(itr1==dino.end()||itr2==ppl.end()){
            cout<<cost<<endl;
            break;
        }

        int dino = (*itr1).first  ;
        int ppl  = (*itr2).first ;

        if(ppl==dino){

            cost += dino*abs((*itr1).second - (*itr2).second);
             itr1++; itr2++;
        }

        else if(ppl>dino){

            (*itr2).first = (*itr2).first - dino;
            cost +=  dino*abs((*itr1).second - (*itr2).second);
            itr1++;
        }
        else{

            (*itr1).first = (*itr1).first - ppl;
            cost += ppl*abs((*itr1).second - (*itr2).second);
            itr2++;
        }

    }
}

return 0;
}
