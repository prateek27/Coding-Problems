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


char s[MAX];
int a[MAX][MAX];
int dp[MAX][MAX][2];
int shadow[MAX][MAX];

int main(){
int t,i;
cin>>t;
while(t--){
    int n,m;
    si(n); si(m);

    FOR(i,0,n){
        scanf("%s",s);
        FOR(j,0,m)
        a[i+1][j+1]=s[j]-'0';
        }
    CLEAR(dp);
    CLEAR(shadow);

    //Fill the shadow matrix
    FOR(i,1,n+1){
        FOR(j,1,m+1){
        if(a[i][j]){
            shadow[i][j-1]++;
            shadow[i][j+1]++;
            shadow[i-1][j]++;
            shadow[i+1][j]++;
            }
        }
    }
    //Set the first row and col as INF
    FOR(i,0,n+1)
        shadow[i][0] = 0;
    FOR(j,0,m+1)
        shadow[0][j] = 0;
    //MAKE THE DP Solution
    dp[1][1][0]=shadow[0][0]-a[0][0];
    dp[1][1][1]=shadow[0][0]-a[0][0];


    //FILL THE 0TH ROW AND 0TH COLUMN
    dp[0][0][0]=0;


    FOR(i,1,n+1){
        FOR(j,1,m+1){

            int x = min(dp[i][j-1][0],dp[i][j-1][1]-a[i-1][j]);
            dp[i][j][0] = shadow[i][j] - a[i][j] + (i==1?dp[i][j-1][0]:x);

            int y = min(dp[i-1][j][1],dp[i][j-1][0]-a[i][j-1]);
            dp[i][j][1] = shadow[i][j] - a[i][j] + (j==1?dp[i-1][j][1]:y);

        }
    }
cout<<dp[n][m][0]<<endl;
cout<<dp[n][m][1]<<endl;
}
return 0;
}
