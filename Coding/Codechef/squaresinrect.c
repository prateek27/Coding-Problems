#include<stdio.h>
#include<conio.h>


int main(){
     int i,j,n,m;
     scanf("%d%d",&n,&m);
     int a[n][m];
     
    /* for(i=0;i<n;i++)
     {
                     for(j=0;j<m;j++){
                                      scanf("%d",&a[i]);
                                      }
     }/*/
     int t=  n-m>0?n-m:m-n;
     int lesser=(m>n?m:n);
     int ans=0;
     for(i=1;i<=lesser;i++){
             ans=ans+i*i+i*t;               
                            
              }
              
              printf("%d",ans);
     
     
 
   getch();
   return 0;
}

  
 
  
    
    
    
    
    

