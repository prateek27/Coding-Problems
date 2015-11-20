#include<iostream>
using namespace std;

int coeff(int n,int k){
int dp[n+1][k+1];
int i,j;
for(i=0;i<=n;i++)
{
    for(j=0;j<=min(i,k);j++)
    {
        if(j==0||j==i)
            dp[i][j]=1;
        else
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    }
}
return dp[n][k];
}


int main(){
int n,k;
cin>>n>>k;
cout<<coeff(n,k);
return 0;
}
