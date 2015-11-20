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

int kapacity[505];
int houseDist[505];
int dp[505][1010];
int i,j;

int frameDPSolution(int N,int M){
// dp[i][j] i means use stations from 1 to i , j means collect j litres of fuel
// dp[0][0] = 0 attempts , dp[0][1] = -1 invalid case , dp[i][0] = 0

CLEAR(dp);
        FOR(j,1,M+1)
            { dp[0][j]=1000000000;}

        dp[0][0]=0;

        FOR(i,1,N+1){
            FOR(j,1,M+1){
                dp[i][j] = dp[i-1][j];
                if(j>=kapacity[i])
                dp[i][j]= min(dp[i][j],dp[i][j-kapacity[i]]+1);
                }
        }

}


int main(){
int tc,i,j;
si(tc);
while(tc--){
        int N,i;
        si(N);
        FOR(i,1,N+1){
        si(houseDist[i]);
        }

        int maxCapacity=-1;
        FOR(i,1,N+1){
        si(kapacity[i]);
        maxCapacity=max(kapacity[i],maxCapacity);
        }

        frameDPSolution(N,2*maxCapacity);

int ans=0;
FOR(i,1,N+1){
ans+=dp[N][2*houseDist[i]];
}
printf("%d\n",ans);
}
return 0;
}
