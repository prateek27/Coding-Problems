#include<stdio.h>

int main(){
    int t;
    long n[1000];
    int i=0;
    scanf("%d",&t);
    while(t){
             
             scanf("%li",&n[i]);
             i++;
             t--;
     }
     for(int j=0;j<t;j++)
     {
             printf("%li",n[i]/2+1);
     }
     
     getch();
     return 0 ;
}
