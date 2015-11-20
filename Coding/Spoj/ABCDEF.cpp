#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll arr[105];
ll x[1000005];
ll y[1000005];




int main()
{
int n,i;
cin>>n;
ll ans=0;
for(i=0;i<n;i++)
    scanf("%lld",&arr[i]);

int a,b,c,d,e,f;
int l=0,r=0;

for(a=0;a<n;a++)
    for(b=0;b<n;b++)
        for(c=0;c<n;c++)
            x[l++]=arr[a]*arr[b]+arr[c];


for(d=0;d<n;d++)
    for(e=0;e<n;e++)
        for(f=0;f<n;f++)
            y[r++]=arr[d]*(arr[e]+arr[f]);

sort(x,x+l);
sort(y,y+r);

i=0;
int j=0;


i=0;
j=0;
int count=0;
while(i<l&&j<r){

    if(x[i]<y[j])
        i++;
    else if(x[i]>y[j])
    j++;
    else {

        ll countX=1,countY=1;
        while(x[i]==x[i+1])
        {
            countX++;
            i++;
        }

        while(y[j]==y[j+1])
        {
            countY++;
            j++;
        }
        ans += countX*countY;

        i++;
        j++;
    }
}

printf("%lld\n",ans);

return 0;
}
