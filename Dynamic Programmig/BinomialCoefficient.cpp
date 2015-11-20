#include<bits/stdc++.h>
using namespace std;

int BinomialCoefficientDP(int n,int k){

    int **dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[k+1];
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i){
                dp[i][j]=1;
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }

        }

    }

int ans = dp[n][k];

for(int i=0;i<=n;i++){
    delete dp[i];
}

return ans;
}


int BinomialCoefficientRecursive(int n,int k){
    if(k==0||n==k){
        return 1;
    }
    return BinomialCoefficientRecursive(n-1,k-1)+BinomialCoefficientRecursive(n-1,k);
}


int main(){
 cout<<BinomialCoefficientRecursive(5,2)<<endl;
 cout<<BinomialCoefficientDP(5,2)<<endl;


}
