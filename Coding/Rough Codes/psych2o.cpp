
#include<stdio.h>
#include<math.h>
#define int long long
main(){
int n,t,even,odd,count,k,i;
scanf("%lld",&t);
while(t--){
    scanf("%lld",&n);
    k=sqrt(n);
    //if(n==1) printf("Ordinary Number\n");
 if(k*k==n) printf("Psycho Number\n");
    else{
    even=0,odd=0,count=0;
    while (!(n&1))
    {
        count++;
        n >>=1;
    }

    if(count&1) { odd++;}
    else if(count>0){even++; }

    for (i = 3; i<=k; i = i+2)
    {
       count=0;
        while (n%i == 0)
        {
            count++;
            n = n/i;
         }

         if(count&1) {odd++;}
         else if(count>0) {even++;}

    }
   if (n > 2){
    { odd++; }}
if(even>odd)
    printf("Psycho Number\n");
else
    printf("Ordinary Number\n");
}}
return 0;
}
