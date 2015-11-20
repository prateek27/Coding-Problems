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


int c[105],p[105],t[105];
int dp[105][105];

int main(){
int tc;
si(tc);
while(tc--){
    int N,T,i,j;
    si(N);
    si(T);
    CLEAR(dp);
    FOR(i,1,N+1){
    si(c[i]);
    si(p[i]);
    si(t[i]);
    }
    FOR(i,0,T+1){
    dp[0][i]=0;
    }
    //Frame the Knapsack type DP Solution
    FOR(i,1,N+1){
        FOR(j,1,T+1){
            if(t[i]<=j){
                dp[i][j] = max(dp[i-1][j],c[i]*p[i]+dp[i-1][j-t[i]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
printf("%d\n",dp[N][T]);
}
return 0;
}
