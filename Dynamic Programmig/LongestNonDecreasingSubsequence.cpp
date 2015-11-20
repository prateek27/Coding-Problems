#include<bits/stdc++.h>
using namespace std;

int findLIS(int *a,int n){
int *dp = new int[n];
for(int i=0;i<n;i++){
    dp[i] = 1;
}
for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(a[j]<=a[i]){
            dp[i] = max(dp[i],dp[j]+1);
        }

    }

}
int ans = INT_MIN;
for(int i=0;i<n;i++){
    ans = max(ans,dp[i]);
}
delete [] dp;
return ans;
}


int main(){

int a[]= { 10, 22, 9, 33, 21, 50, 41, 60, 80 } ;
int n = sizeof(a)/sizeof(int);
cout<<findLIS(a,n);

return 0;
}
