#include<iostream>
#include<climits>
using namespace std;

//--------------------------------------Recursive Solution
int optBST(int freq[],int i,int j){

if(i==j){
    return freq[i];
}

if(j<i){
    return 0;
}

int freqTotal = 0;
for(int v = i;v<=j;v++){
    freqTotal += freq[v];
}

int subans = INT_MAX;
    for(int root=i;root<=j;root++){
        subans = min(subans, optBST(freq,i,root-1)+ optBST(freq,root+1,j));
    }


return subans+freqTotal;
}

//----------------------------------------Top Down DP Solution
int sum(int *freq,int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum += freq[k];
    }
return sum;
}

int optBSTDP1(int *freq,int n){

int dp[100][100]={0};

for(int i=0;i<n;i++){
    dp[i][i]=freq[i];
}

for(int len=2;len<=n;len++){
    for(int i=0;i<=n-len+1;i++){
        int j = i+len-1;

        dp[i][j]=INT_MAX;

        for(int root = i;root<=j;root++){

            int cost = ((root>i)? dp[i][root-1]:0)  + ((root<j)?dp[root+1][j]:0) + sum(freq,i,j);

            dp[i][j] = min(dp[i][j],cost);
            //cout<<cost<<endl;
        }

    }
}


return dp[0][n-1];
}





int main(){

//Key should be sorted in ascending order.
int keys[] = {10, 12, 20 };
int freq[] = { 34, 8, 50};

cout<<optBST(freq,0,2)<<endl;
cout<<optBSTDP1(freq,3)<<endl;
return 0;
}
