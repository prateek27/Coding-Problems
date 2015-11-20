#include<iostream>
#include<cstdio>
using namespace std;



int a[1000005];

int main()
{
int n;
int i,j,k,pos;
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
scanf("%d",&k);

pos=0;

int mx=a[1];
for(i=1;i<=n-k+1;i++)
{


    for(j=i;j<i+k;j++)
    {
        if(a[j]>mx)
        {
            mx=a[j];
            pos=j;
        }
    }

cout<<a[pos];
}



return 0;
}

