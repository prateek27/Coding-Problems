#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int a[1000005];



int main(){

int n,i;
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%d",&a[i]);

sort(a,a+n);
for(i=0;i<n;i++)
printf("%d\n",a[i]);


}

