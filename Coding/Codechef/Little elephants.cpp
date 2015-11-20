#include<stdio.h>
#include<conio.h>
int main(){
    int t,n,i;
    long c;
    long candies[100],sum=0;
    
    scanf("%d",&t);
    while(t)
    {   scanf("%d",&n); 
            scanf("%li",&c);
             
            
            for(i=0;i<n;i++){                            
            scanf("%li",&candies[i]);
            }
            for(i=0;i<n;i++){
           
            sum=sum+candies[i];         
               
            }
            
           
            
            if(sum<=c)
            printf("Yes\n");
            else
            printf("No\n");
            sum=0;
            t--;
}
getch();
return 0;
}
    
