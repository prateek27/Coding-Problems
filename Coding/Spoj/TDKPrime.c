#include<stdio.h>
#include<math.h>
#define MAX 5000000
int main()
{
int t,k,count=0;
scanf("%d",&t);
while(t--){
    scanf("%d",&k);
    int i,j,primes[500];
    for(i=0;i<MAX;i++) primes[i] = 1;

    for(i=2;i<=(int)sqrt(MAX);i++)
    if (primes[i]){
    for(j=i;j*i<MAX;j++) primes[i*j] = 0;
    count++;                 //Count of non-primes;
    if(i-count==k)
    {
        printf("%d",j);
    }

    }




}
return 0;
}
