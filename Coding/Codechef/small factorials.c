#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    if(n>=1&&n<=100){
    int a[n];
    long int fact;
    
    for(i=0;i<n;i++)
    {
                    
     scanf("%d",&a[i]);
    }
    
   for(i=0;i<n;i++)
    {
      fact=1;
      int num=a[i];
     while(num>=1)
     {
                 fact=fact*num;
                 num--;  
                 
     }
     printf("%ld\n",fact);
    }}
    
    getch();
    return 0;
}
