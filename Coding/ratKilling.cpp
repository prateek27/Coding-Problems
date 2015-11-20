#include<iostream>
#include<cstdio>
using namespace std;
#define si(n) scanf("%d",&n)

int killed[1025][1025];

int main()
{
int t;
si(t);
while(t--)
{   int d,n;
    si(d);
    si(n);
    while(n--)
    {   int x,y,size;
        si(x);si(y);si(size);
        int i,j;
        for(i=x-d;i<=x+d;i++)
        {
            for(j=y-d;j<=y+d;j++)
            {
                if(i>=0)
                    killed[i][j]+=size;
                if(j>=0)
                    killed[i][j]+=size;
                if(i>=0&&j>=0)
                    killed[i][j]-=size;
            }
        }
    }
int i,j,max=0;
int cx,cy;
for(i=0;i<=1024;i++)
{
    for(j=0;j<=1024;j++)
    {
        if(killed[i][j]>=max)
        {   cx=i;
            cy=j;
            max=killed[i][j];
            killed[i][j]=0;
        }
    }
}
printf("%d %d %d\n",cx,cy,max);
}
return 0;
}
