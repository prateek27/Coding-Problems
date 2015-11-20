#include<iostream>
using namespace std;

int RodCuttingDP(int *costs,int L)
{
int dp[L+1];
dp[0] = 0;

for(int len=1;len<=L;len++){
    int ans = 0;
    for(int current_cut=1;current_cut<=len;current_cut++){
        ans = max(ans,costs[current_cut-1]+dp[len-current_cut]);
    }
    dp[len] = ans;

}

return dp[L];
}


//Lengths are assumed like 1,2,3,4....n.
int RodCuttingRecursive(int *costs,int L){
if(L==0){
    return 0;
}

int ans = 0;
//Make cuts of all possible lengths.
//Don't make a cut of length 0 that would not reduce our problem.
for(int cut_len = 1;cut_len<=L;cut_len++){

    int current_ans = costs[cut_len-1] + RodCuttingRecursive(costs,L-cut_len);
    ans = max(ans,current_ans);
}

return ans;
}

int main(){


int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
int n = sizeof(arr)/sizeof(int);

cout<<RodCuttingRecursive(arr,n)<<endl;

cout<<RodCuttingDP(arr,n)<<endl;

return 0;
}
