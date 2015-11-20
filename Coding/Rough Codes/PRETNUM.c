#include<stdio.h>
#include<math.h>
#define int long long

int count_div(int n){
int i,count=0,ans=1;
while(n&1==0)
{ n=n>>1;
  count++;
}
ans=ans*(count+1);
count=0;
for(i=3;i<=sqrt(n);i+=2)
{
while(n%i==0) { count++; n=n/i; }
ans=ans*(count+1);
count=0;
}
if(n>2)
    ans=ans*2;

return count;
}

int main(){
int t,l,r;
scanf("%lld",&t);
while(t--){
    scanf("%lld%lld",l,r);

count_div(l);

}


return 0;
}
