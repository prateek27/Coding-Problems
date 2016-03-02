#include<iostream>
#include<climits>
using namespace std;


int matrixChainDp(int *p,int n){
// Not using the 0th row and  0th column.
// Here n = 4 , whereas matrices are 1,2,3 only.

int dp[100][100];


for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        dp[i][j] = INT_MAX;
    }
}

for(int i=1;i<n;i++){
   dp[i][i] = 0;
}

//max len will be 3 only.
for(int len = 2;len <n ; len++){
    for(int i = 1; i <= n - len +1 ;i++)
    {
     int j = i + len -1;
     for(int k=i;k<j;k++){
        dp[i][j] = min( dp[i][j],dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
        }
    }

}

return dp[1][n-1];
}

int main(){

int arr[] = {1, 2, 3, 4};
//There are actually 3 matrices for n=4.
cout<<matrixChainDp(arr,4);

return 0;
}



