#include<stdio.h>

int main()
{
    long int n,i,j,temp,key;
    scanf("%ld",&n);
    long int a[n];
    for(i=0;i<=n;i++)
    {
    scanf("%ld",&a[i]);
    }
    
    for(i=1;i<n;i++)
    {
      key=a[i];
      j=i-1;
      while(j>=0&&a[j]>a[j+1])
      {
         temp=key;
      a[j+1]=a[j];
      a[j]=temp;
       j--;
      }
     printf("%ld",a[i]);
     } 
     
     getch();
     return 0;
}
                                            
