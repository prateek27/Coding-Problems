#include<iostream>
#include<bitset>
#include<algorithm>
#include<vector>
#define MAX 100000007
#define ll int
#include<cstdio>
#include<cmath>
using namespace std;

bitset<MAX> primes(0);
vector<int> myVector;
ll k=2;

void sieve(){
ll i,j;
for(i=4;i<MAX;i+=2) primes[i]=1;
for(i=6;i<MAX;i+=3) primes[i]=1;

myVector.push_back(2);
myVector.push_back(3);

for(i=5;i*i<MAX;){
    if(primes[i]==0)
    {   myVector.push_back(i);
        for(j=i*i;j<MAX;j+=2*i)
           primes[j]=1;
    }
    if(i%6==1) i+=4;
    else i+=2;
    }

for(;i<MAX;i++){
    if(primes[i]==0)
         myVector.push_back(i);
}
}




int main(){

ll t,n;

    sieve();
printf("done!!");
   /* scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    printf("%d\n",myArray[n-1]);
    }
*/
return 0;
}
