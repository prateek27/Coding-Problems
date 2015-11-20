#include<iostream>
#include<cstdio>
using namespace std;

int a[1005];
int arr[1005];

int lds(int start,int last)
{
    int i,j;
        int lis[last-start+1];
        for(i=start;i<=last;i++)
            lis[i]=1;

        for(i=start+1;i<=last;i++)
        {
            for(j=start;j<i;j++)
               if(a[i]<a[j]&&lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1;
        }
    int max=0;
    for(i=start;i<=last;i++)
        if(lis[i]>max)
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

int caseA = lds(0,n-1);
ans=caseA;
if(p!=n-1)
{
int caseB = lds(0,p)+ lds(p+1,n-1);
ans=max(caseA,caseB);
}
printf("%d\n",ans);
}
return 0;
}
