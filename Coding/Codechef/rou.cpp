#include<iostream>
#include<cstdio>

using namespace std;

long long a[100005];

int main(){
long long n,k;
int i;
cin>>n>>k;

    for(i=0;i<n;i++){
    scanf("%lld",&a[i]);
    }

if(k==0){
for(i=0;i<n;i++)
printf("%lld ",a[i]);
}

else{

long long max1= a[0];

for(i=1;i<n;i++)
if(a[i]>max1)
max1 = a[i];

for(i=0;i<n;i++)
{
a[i]= max1 - a[i];
}

long long max2 = a[0];

for(i=1;i<n;i++){
if(a[i]>max2)
max2=a[i];
}


k--;

if(k&1)
{
for(i=0;i<n;i++)
printf("%lld ",max2-a[i]);
}

else{
for(i=0;i<n;i++)
printf("%lld ",a[i]);
    }
}
return 0;
}
