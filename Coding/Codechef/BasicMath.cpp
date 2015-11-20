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

ll multiply(ll a,ll b,ll mod){
ll res = 0 ;
ll x = a%mod;

while(b>0){
    if(b&1)
     res = (res+x)%mod;

    a = (a*2)%mod;
    b>>=1;
    }
return res%mod;
}


ll fastPower(ll a,ll b,ll mod){
    int res=1;
    a=a%mod;
    while(b>0)
    {
        if(b&1)
            res=(res*a)%mod;
     a=(a*a)%mod;
     b>>=1;
    }
return res%mod;
}

ll inverseMod(ll no,ll mod){
    return fastPower(no,mod-2,mod);
}

ll square(ll a){
return multiply(a,a,MOD);
}

ll ncr(ll n,ll k,ll mod){
    if(k>n/2)
        return ncr(n,n-k,mod);
    ll num = 1;
    ll nth = n;
    for(ll i=0;i<k;i++){
        num = multiply(num,nth,mod);
        nth--;
    }
    ll denom=1;
    for(ll i=2;i<=k;i++)
        denom=multiply(denom,i,mod);

return multiply(num,inverseMod(denom,MOD),MOD);

}




int main(){
int t;
si(t);
ll n,k;
while(t--)
{
    sl(n); sl(k);
    ll a1 = ncr(n,k-1,MOD);
    ll a2 = square(a1);
    ll num = multiply(a2,n-k+1,MOD);
    ll denom = multiply(n,k,MOD);
    ll ans = multiply(num,inverseMod(denom,MOD),MOD);
    cout<<a1<<endl<<a2<<endl<<num<<endl<<denom<<endl<<ans<<endl;
}
return 0;
}
