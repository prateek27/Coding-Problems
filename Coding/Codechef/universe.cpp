#include<stdio.h>
#include<conio.h>
int main()
{   
    int a[100];
    int i=0,j;
    do{
        
    scanf("%d",&a[i]);
     
     
     i++;printf("%d",a[i-2]);
    }
    while(a[i-2]!=42);
    for(j=0;j<i-2;j++)
    {
    printf("%d\n",a[j]);
    }
    getch();
    return 0;
}    
    
