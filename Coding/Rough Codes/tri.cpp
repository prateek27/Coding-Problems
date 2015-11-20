#include<iostream>
#include<math.h>
#include<stdio.h>
#include<ctime>
using namespace std;

int isprime(int);

int primeFactors(int n)
{
    while (n%2 == 0){
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {

        while (n%i == 0)
        {

            if(i%4==1) return 1;
            n = n/i;

        }
    }


    if (n > 2&&n%4==1) return 1;

return 0;
}

int isprime(int n)
   {
   if(n==1) return 0;
   if(n==2) return 1;
   if (n==3) return 1;
   if (n%2==0) return 0;
   if (n%3==0) return 0;

   int i = 5;
    int w = 2;
   while (i*i<= n){
         if (n%i==0){

         return 0;}

      i += w;
      w = 6 - w;
   }
   return 1;
   }



int main(){

int t,i,temp;
int n;int start,end;
start=clock();
scanf("%d",&t);


while(t--){
temp=0;
scanf("%d",&n);

if(isprime(n)&&n%4==1)
temp=1;

else
{
    if(primeFactors(n))
    temp=1;
}




if(temp){ printf("YES\n");}
else printf("NO\n");
}
end=clock();
cout<<end-start;


return 0;
}
