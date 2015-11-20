#include<stdio.h>
#include<conio.h>

int main(){
     int n;
     scanf("%d",&n);
     long a[n],i,j,sum=0;
     
     for(i=0;i<n;i++){
                     scanf("%ld",&a[i]); 
                     }
     for(j=i+1;i<n;j++){
                      for(j=i+1;j<n;j++){
                      sum=sum+(a[i]&a[j]) ;              
                       }                   
                      
                      
                      
                      }
                      printf("%ld",sum);
   getch();
   return 0;
}
