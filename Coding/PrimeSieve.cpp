#include<iostream>
#include<bitset>
#include<algorithm>
#include<vector>
#define MAX 1007
#define ll int
#include<cstdio>
#include<cmath>
using namespace std;

bitset<MAX> primes(0);
int myArray[1007];
int k=2;

void sieve(){
int i,j;
for(i=4;i<MAX;i+=2) primes[i]=1;
for(i=6;i<MAX;i+=3) primes[i]=1;

myArray[0]=2;
myArray[1]=3;

for(i=5;i*i<MAX;){
    if(primes[i]==0)
    {  myArray[k++]=i;
        for(j=i*i;j<MAX;j+=2*i)
           primes[j]=1;
    }
    if(i%6==1) i+=4;
    else i+=2;
    }

for(;i<MAX;i++){
    if(primes[i]==0)
         myArray[k++]=i;
}
}
int countFactors(long long n){
if(n==1) return 0;

long long count=0;

if((n&1)==0)
{  count++;
while((n&1)==0) n=n>>1;
}

for(int i=1;myArray[i]<=sqrt(n);i++)
{
    if(n%myArray[i]==0)
        {
            while(n%myArray[i]==0){
             n/=myArray[i];
             }
             count++;
        }

}
if(n>1)
count++;
return count;
}



int main(){
sieve();
long long t,a,b,n;
scanf("%lld",&t);
int var=0;
while(t--){
scanf("%lld%lld%lld",&a,&b,&n);

for(int i=a;i<=b;i++){

    if(countFactors(i)==n)
    {
        var++;
    }
}
printf("%d\n",var);
var=0;
}

return 0;
}

