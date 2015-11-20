#include<iostream>
#include<cstdio>
using namespace std;

int a[1000000];
int main(){
int  t,i;
int  n,temp=1;
long long ninja=1;
scanf("%d",&t);
while(t--)
{
    scanf("%d",&n);
    for(i=0;i<n;i++) cin>>a[i];
    ninja=1;
    for(i=0;i<n;i++){
        ninja=ninja-a[i];

        if(ninja<0) { temp = 0 ;break; }
        ninja=2*ninja;
}
if(temp&&ninja==0)
    printf("Yes\n");
else
     printf("No\n");
temp=1;
}



return 0;
}
