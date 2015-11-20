#include<iostream>
using namespace std;

int isprime(int n)
   {if(n==2) return 1;
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

cout<<isprime(37);

return 0;

}
