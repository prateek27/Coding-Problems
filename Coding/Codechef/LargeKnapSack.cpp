#include<iostream>
#include<cstdio>
using namespace std;

int wt[501],val[501];

int dp[200001][2];



int knapsack(int w,int n)
{
    int i,j;

    for(i=0;i<=w;i++)
    {
    dp[0][i]=0;
    }



    for(i=1;i<=n;i++)
    {

        for(j=1;j<=w;j++)
        {


         if(i&1){
            if(j==0)
                dp[1][j]=0;

            if(wt[i-1]<=j){
              dp[1][j]= max( val[i-1]+dp[0][j-wt[i-1]], dp[0][j] );

            }
            else
              {
                dp[1][j]=dp[0][j];}

         cout<<dp[1][j]<<" ";
         }

         else{
            if(j==0)
                dp[0][0]=0;

             if(wt[i-1]<=j)
             dp[0][j]= max(val[i-1]+dp[1][j-wt[i-1]],dp[1][j]);

            else
            dp[0][j]=dp[1][j];
            cout<<dp[0][j]<<" " ;
            }

        }
        cout<<endl;

    }

return max(dp[0][w],dp[1][w]);
}

int main(){

int k,n,i;
scanf("%d%d",&k,&n);
for(i=0;i<n;i++)
{
    scanf("%d%d",&val[i],&wt[i]);
}
int ans = knapsack(k,n);
cout<<ans;
return 0;
}
