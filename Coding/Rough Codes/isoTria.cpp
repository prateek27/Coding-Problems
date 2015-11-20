#include<iostream>
#include<math.h>
#include<cstdio>

using namespace std;


int fun(long long n){
long long i;double height;
long long k=n*n;
//for(i=2;i<2*n;i+=2){
for(i=2*n-2;i>=2;i-=2){
height=(double)sqrt(k-i*i/4);
if(height-(int)height == 0)  return 1 ;
}
return 0;
}



int main(){
long long n;
int t;
cin>>t;
while(t--)
    {
         scanf("%lld",&n);
         if(fun(n)) printf("YES\n");
         else printf("NO\n");
        }

return 0;
}

