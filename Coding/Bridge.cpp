#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct dj{
int x;
int y;
}a[1000];
inline int myf(dj dj1,dj dj2)
{
if(dj1.x<dj2.x)
return 1;
if(dj1.x==dj2.x)
if(dj1.y<dj2.y)
return 1;
return 0;
}
int main()
{
int n,t,L[1005],len;
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
for(int i=0;i<n;i++)
scanf("%d",&a[i].x);
for(int i=0;i<n;i++)
scanf("%d",&a[i].y);

sort(a,a+n,myf);

L[0]=1;
len=1;
for(int i=1;i<n;i++)
{
L[i]=1;
for(int j=0;j<i;j++)
{
if((a[i].y>=a[j].y)&&(L[i]<L[j]+1))
L[i]=L[j]+1;
}
if(len<L[i])
len=L[i];
}
printf("%d\n",len);
}
return 0;
}
