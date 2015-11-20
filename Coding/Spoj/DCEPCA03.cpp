#include<iostream>
#include<cstdio>
using namespace std;

int fi(int n)
     {
       int result = n;
       for(int i=2;i*i <= n;i++)
       {
         if (n % i == 0) result -= result / i;
         while (n % i == 0) n /= i;
       }
       if (n > 1) result -= result / n;
       return result;
     }

int totient[10000];
int main(){

int H=0,n,i,t,j;
for(i=1;i<=10000;i++)
{totient[i]=fi(i);}

scanf("%d",&t);


while(t--){
      scanf("%d",&n);
for( i=1;i<=n;i++){

                for( j=1;j<=n;j++){

                    H=H+totient[i]*totient[j];

          }

}

printf("%d\n",H);
H=0;
}

return 0;
}
