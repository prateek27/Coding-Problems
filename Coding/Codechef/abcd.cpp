#include<iostream>
#include<bitset>
#include<algorithm>
#include<vector>
#define MAX 1000005
#define ll int
#define sl(n)  scanf("%d",&n)
#include<cstdio>
#include<cmath>
using namespace std;

bitset<MAX> primes(0);
//ll myArray[5000000];
ll k=2;

void sieve(){
ll i,j,l;
for(i=4;i<MAX;i+=2) primes[i]=1;
for(i=6;i<MAX;i+=3) primes[i]=1;

//myArray[0]=2;
//myArray[1]=3;

for(i=5,l=7;i*i<MAX||l*l<MAX;i+=6,l+=6){
    if(primes[i]==0)
    {  //myArray[k++]=i;
        for(j=i*i;j<MAX;j+=2*i)
           primes[j]=1;
    }
    if(primes[l]==0)
    {  //myArray[k++]=l;
        for(j=l*l;j<MAX;j+=2*l)
           primes[j]=1;
    }
    }

}




int main(){
sieve();
primes[1]=1;
int t,n;
scanf("%d",&t);
//int mark[1000001];

while(t--)
{
int ans=0;
cin>>n;
int i;

for(i=1;i<=n;i++){

    if(primes[i]==0&&(i%4==1)){
        ans+=1;
       cout<<i<<endl;
        }
    if((i&1)&&(i%5==0)&&primes[i/5]==0)
    {
     cout<<i<<endl;
     ans+=1;
    }

    }


cout<<"Ans"<<ans<<endl;

}
return 0;
}




