#include<stdio.h>
#include<conio.h>
int main()
{
    long int n;int i,num,j=5,temp,sum=0;
    scanf("%ld",&n);
    int a[100];
    for(i=0;i<n;i++)
    {
      scanf("%ld",&a[i]);              
    }            
    
    for(i=0;i<n;i++)
    {    
     sum=0;temp=1;j=5;      //Dont forget to reinitalize j.BLUNDER !!
     while(temp!=0)
     { 
       temp=a[i]/j;
       
       sum=sum+temp;
       
       j=j*5; 
                 
      }                         
      printf("%d\n",sum);                        
    } 
    getch();
    return 0;
}
                
