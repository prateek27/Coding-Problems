#include<iostream>
using namespace std;


int maxSumIncreasingSub(int *a,int n){
int dp[n+1];


for(int i=0;i<n;i++)
    dp[i] = a[i];


for(int i=0;i<n;i++){
 int sum = 0;
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            sum = max(sum,dp[j]+a[i]);;
        }
    dp[i]=sum;
    }

}
int ans=0;
for(int i=0;i<n;i++){
ans = max(ans,dp[i]);
}
return ans;
}


int main(){

    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSumIncreasingSub(arr,n);
return 0;
}
