#include<stdio.h>
#include<conio.h>

int main(){
    int n ,q;
    scanf("%d,%d",&n,&q);
    int a[n],b[3];
    int i,j,k,count=0;
    for(i=0;i<=n;i++){
                      scanf("%d",&a[i]);
                      }
                      
                      for(i=0;i<q;i++)
                      {
                                      for(j=0;j<3;j++){
                                      scanf("%d",&b[i]);
                                      
                                      }
                                      for(k=b[0];k<=b[1];k++)
                                      {
                                        if(a[k]%b[3]==0){
                                                         count++;
                                                         }
                                                         }
                      
 
                      printf("%d",count);
                      }
                      
  getch();
  return 0;
}                                   
     
