#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define si(n) scanf("%d",&n);
#define REP(i,a,n) for(int i=a;i<n;i++)
int a[105];
bool forw[105];
bool backw[105];


int lis(int n)
{
int mx=-1;
int ans1=0,ans2=0;
int mxElement=-1;
int dp[105];
int i,j;
    for(i=0;i<n;i++)
        dp[i]=1;

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        if(dp[i]>mx)
        {
            ans1=mx=dp[i];
            mxElement=i;
        }
    }

    int start1=mxElement;
    forw[mxElement]=false;
    for(i=start1-1;i>=0;i--)
    {
        if(a[i]<a[mxElement])
        {forw[i]=false;
         mxElement=i;
        }
    }

    for(i=0;i<n;i++)
    dp[i]=1;
    mx=-1;

    for(i=n-2;i>=0;i--)
    {
        if(forw[i]){
        for(j=n-1;j>i;j--)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1&&forw[j]==true)
                dp[i]=dp[j]+1;
        }
        if(dp[i]>mx)
        {
            ans2=mx=dp[i];
            //mxElementR=i;
        }
    }
    }


return ans1+ans2;
}


int lisReverse(int n)
{
int mx=-1;
int mxElementR=-1;
int dp[105];
int i,j;
int ans3=0;int ans4=0;
    for(i=0;i<n;i++)
        dp[i]=1;

    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        if(dp[i]>mx)
        {
            ans3=mx=dp[i];
            mxElementR=i;
        }
    }

    backw[mxElementR]=false;
    int start2=mxElementR;
    for(int i=start2+1;i<n;i++)
    {
        if(a[i]<a[mxElementR])
        {
            mxElementR=i;
            backw[i]=false;
        }
    }
    //----------------------
    mx=-1;
    for(i=0;i<n;i++)
        dp[i]=1;

    for(i=1;i<n;i++)
    {
        if(backw[i]){
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j]&&dp[i]<dp[j]+1&&backw[j]==true)
                dp[i]=dp[j]+1;
        }
        if(dp[i]>mx)
        {
            ans4=mx=dp[i];
            //mxElement=a[i];
        }}
    }



return ans3+ans4;
}


int main(){
int t,n;
si(t);
while(t--)
    {
       si(n);
       REP(i,0,n)
       { forw[i]=true; backw[i]=true; }

       REP(i,0,n)
       {si(a[i]);}
       int ans=max(lis(n),lisReverse(n));
       printf("%d\n",ans);
    }


return 0;
}
