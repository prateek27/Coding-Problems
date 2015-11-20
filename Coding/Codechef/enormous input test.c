#include<stdio.h>
#include<conio.h>
int main(){
    long int n,k,count=0,i,j;
    
    scanf("%ld %ld",&n,&k);
    long int a[n];
    for(i=0;i<n;i++)
    {
    scanf("%ld",&a[i]);
    }
    for(i=0;i<n;i++)
    {
      if(a[i]%k==0)
      {
       count++;
       }
      }  
     printf("%ld",count);


getch();
return 0;
} 
                       
