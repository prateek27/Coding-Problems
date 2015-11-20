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

int a[250][250];
int dp[250][250][2];

int main(){
int t,i,j;
cin>>t;
while(t--){
    int n,m;
    si(n);
    si(m);

    //Scan the input starting from 1,1
    string s;
    FOR(i,0,n){
        cin>>s;
        FOR(j,0,m){
            if(s[j]=='T')
                a[i+1][j+1]=2;

            else if(s[j]=='0')
                a[i+1][j+1]=1;
            else
                a[i+1][j+1]=0;
        }
    }
    CLEAR(dp);
    // 0 means facing right , 1 means facing left .
    //Make a bottom up dp solution
    FOR(i,1,n+1){
        FOR(j,1,m+1){   //Left to Right
        if(a[i][j])
            dp[i][j][0] = max(dp[i][j-1][0],dp[i-1][j][1]) + a[i][j]-1;
        }
        RFOR(j,m+1,1) //Right to Left
         if(a[i][j])
            dp[i][j][1] = max(dp[i][j+1][1],dp[i+1][j][0]) + a[i][j] - 1;
    }
printf("%d\n",dp[1][1][1]);
}
return 0;
}


