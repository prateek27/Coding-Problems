#include<iostream>
#include<cstdio>
#include<bitset>

using namespace std;
#define MAX 1562500
#define ll int
long long a[MAX+1];

bitset<MAX> primes(0);
ll myArray[2000000];
ll k=2;

void sieve(){
//cout<<"Sieve executing..";
ll i,j,l;
for(i=4;i<MAX;i+=2) primes[i]=1;
for(i=6;i<MAX;i+=3) primes[i]=1;

myArray[0]=2;
myArray[1]=3;

for(i=5,l=7;i*i<MAX||l*l<MAX;i+=6,l+=6){
    if(primes[i]==0)
    {  myArray[k++]=i;
        for(j=i*i;j<MAX;j+=2*i)
           primes[j]=1;
    }
    if(primes[l]==0)
    {  myArray[k++]=l;
        for(j=l*l;j<MAX;j+=2*l)
           primes[j]=1;
    }
}

for( ;i<MAX;i++){
    if(primes[i]==0)
         myArray[k++]=i;
}
//cout<<"Out of sieve ";
}

int numFactors(int n){
int ans=1;
int i=0;
int temp=n;

if(primes[n]==0)
    return 2;

while(1)
{


   if(n%myArray[i]==0)
       {
        int count=0;
        while(n%myArray[i]==0)
        {
            count++;
            n=n/myArray[i];

        }
        ans*=(count+1);
        }
   i++;
   if(primes[n]==0&&n!=1)
    return ans*2;

    if(n==1)
    break;
 }
//cout<<"Factors calculated ";
return ans;
}


main(){
int i,j;
long long k;
sieve();

for(i=0;i<=MAX;i++)
    a[i]=0;

a[1]=1;
for(i=2;i<=MAX;i++)
{
a[i]=numFactors(i);
//if(i<15) cout<<i<<" :"<<numFactors(i)<<endl;
}

for(i=2;i<=MAX;i++)
a[i]+=a[i-1];

//cout<<"all facotor ";

int t,n;
long long ans;


scanf("%d",&t);

while(t--){
ans=0;
scanf("%d",&n);
    for(i=1;i<=n-1;i++)
        ans+=a[i*(n-i)-1];

    printf("%lld\n",ans);

}
return 0;
}
