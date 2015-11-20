#include<stdio.h>
#include<conio.h>
int main(){
    int t;
    long n[1000];
    int i=0;
    scanf("%d",&t);
    while(t){
             
             scanf("%li",&n[i]);
             printf("%li\n",(n[i]/2)+1);
             i++;
             t--;
             }
   
     
     getch();
     return 0 ;
}
