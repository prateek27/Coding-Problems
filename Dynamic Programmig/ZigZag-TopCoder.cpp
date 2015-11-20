#include<bits/stdc++.h>
using namespace std;

/* Problem Link : https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493 */
/*Description : Find the longest subsequence with alternating terms */

int findLength(int *a,int n){
int dp[n][2];
for(int i=0;i<n;i++){
    dp[i][0]=0;
    dp[i][1]=0;
}

dp[0][1] = dp[0][0] = 1;

int i,j;
for(i=1;i<n;i++){
    for(j=0;j<i;j++){
        if(a[i] > a[j]){
            dp[i][1] = max(dp[i][1], dp[j][0]+1);
        }
        else{
            dp[i][0] = max(dp[i][0],dp[j][1]+1);
        }
    }
}

int ans = INT_MIN;
for(int i=0;i<n;i++){
    ans = max(ans,max(dp[i][0],dp[i][1]));
}
return ans;
}

int main(){
int a[]=
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955,
600, 947, 978, 46, 100, 953, 670, 862, 568, 188,
67, 669, 810, 704, 52, 861, 49, 640, 370, 908,
477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };

//Returns: 36
int n = sizeof(a)/sizeof(int);

int ans = findLength(a,n);

cout<<ans<<endl;
return 0;
}
