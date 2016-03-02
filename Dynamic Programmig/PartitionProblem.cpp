#include<iostream>
using namespace std;


bool partitionDP(int *arr,int sum,int n){


bool dp[n+1][sum+1];

for(int i=1;i<=sum;i++){
    //ith sum cant be formed by taking 0 elements and i>0.
    dp[0][i] = false;
}
for(int i=0;i<n;i++){
    //0 sum can be formed by all elements by not taking them.
    dp[i][0] = true;
}

for(int i=0;i<n;i++){
    for(int s = 1;s<=sum;s++){

        dp[i+1][s] = dp[i][s];
        if(arr[i]<=s){
            dp[i+1][s] = dp[i][s]|| dp[i][s - arr[i]];
        }

    }
}
return dp[n-1][sum];
}


int main(){

int arr[] = {9, 1, 1, 2, 2, 1};
int n = sizeof(arr)/sizeof(arr[0]);

int sum = 0;
for(int i=0;i<n;i++){
sum += arr[i];
}
if(sum&1){
    cout<<"No";
}
else{
    bool ans = partitionDP(arr,sum/2,n);
    if(ans){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}

return 0;
}
