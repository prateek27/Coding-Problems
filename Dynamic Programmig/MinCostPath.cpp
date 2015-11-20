#include<iostream>
#include<cstring>
using namespace std;



int minCostDP(int cost[3][3],int m,int n){

int dp[m+1][n+1];

dp[0][0]=cost[0][0];

for(int i=1;i<m;i++){
    dp[i][0] = dp[i-1][0] + cost[i][0];
}

for(int i=1;i<n;i++){
    dp[0][i] = dp[0][i-1] + cost[0][i];
}



for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
        dp[i][j] = cost[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
    }
}


return dp[m-1][n-1];
}


int main(){


 int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };



cout<<minCostDP(cost,3,3);

return 0;
}
