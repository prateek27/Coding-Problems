#include<stdio.h>

//Checking for palindrome 
int palindrome(long num){
long reverse=0;
int i,flag=0,temp;
long myNum=num;
while(num!=0){
             
             temp=num%10;
             reverse=reverse*10+temp;
             num=num/10;
             }
             
             if(myNum==reverse)
             flag=1;
             
 return flag;
 
} 
//Checking for prime 
int prime(long num){
    int i,flag=1;
    for(i=2;i<=num/2;i++)
     {   if(num%i==0){
         flag=0;
         break;                //flag 0 means not prime.
     }}
         
     return flag;    
                       
}  

int main(){
    long i;
    long n;
    scanf("%li",&n);
    
    for(i=n;i<=1003002;i++)
    {           
                          if(palindrome(n)&&prime(n))
                          {
                             printf("%li",n);
                             break;
                          }
                          else
                          {
                              n++;
                              continue;
                          }
   }
   
   getch();
   return 0;
   
}
