#include<iostream>
#include<cstdio>
using namespace std;

int a[1005];
int arr[1005];

int lisNormal(int s,int e)
{
    int lis[e-s+1];
    int i,j,max=0;
    for(i=s;i<=e;i++)
        lis[i]=1;

    for(i=s+1;i<=e;i++)
    {
        for(j=s;j<i;j++)
            if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }

    for(i=s;i<=e;i++)
        if(max<lis[i])
            max=lis[i];
return max;
}

int lisModified(int s,int e,int pos)
{
    int lis[e-s+1];
    int i,j,max=0;
    for(i=s;i<=e;i++)
        lis[i]=1;

    for(i=s+1;i<=e;i++)
    {
        for(j=s;j<i;j++)
            if(arr[i]>arr[j]&&lis[i]<lis[j]+1)
                lis[i]=lis[j]+1;
    }

    for(i=s;i<=e;i++)
        if(max<lis[i]&&arr[i]>arr[pos])
            max=lis[i];
return max;
}

int main()
{
int t,n,p,i;
scanf("%d",&t);

while(t--)
{
    scanf("%d%d",&n,&p);

    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        }
        int j;
    for(i=n-1,j=0;i>=0;i--,j++)
    {
        arr[j]=a[i];
    }
int ans;
if(n==2)
    ans=2;
else{
int caseA = lisNormal(0,n-1);
int caseB = lisModified(0,n-2-p,n-1-p)+ lisNormal(n-p,n-1);
ans=max(caseA,caseB);
}
printf("%d\n",ans);
}
return 0;
}
