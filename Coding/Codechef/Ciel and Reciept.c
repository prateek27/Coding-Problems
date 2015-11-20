#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
    int t,items=0;
    long p,left;
    scanf("%d",&t);
    int j;
    
   
    while(t>0){
               scanf("%li",&p);
                
    for(j=11;j>=0;j--)
    {   
        
        int divisor=pow(2,j);
        if(p>=divisor)
       {             items=items + p/divisor;    
                     left=p%divisor;
                     p=left;
                     continue;
       }
                     
}
printf("%i\n",items);
items=0;
t--;
}
getch();
return 0;
}               
    
