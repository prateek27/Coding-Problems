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



    int main(){
    int n,i,j;
    si(n);
    string s;
    cin>>s;
    int dp[2][n+1];
    CLEAR(dp);

    //Frame the DP Solution
    // Recurence is if s[i]== s[j] , dp[i][j] = dp[i+1][j-1] else 1 + min(dp[i+1][j],dp[i][j-1])

    RFOR(i,n,0){
        FOR(j,i+1,n){
            if(s[i]==s[j])
                dp[i%2][j] = dp[(i+1)%2][j-1];
            else
                dp[i%2][j] = 1 + min(dp[(i+1)%2][j],dp[i%2][j-1]);
        }
    }
    printf("%d",dp[0][n-1]);

    return 0;
    }

