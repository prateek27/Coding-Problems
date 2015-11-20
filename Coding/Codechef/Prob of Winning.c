#include<stdio.h>

int main(){
    int t;
    long w,l,ta,d;
    scanf("%d",&t);
    float prob;
    while(t){
             scanf("%li",&w);
             scanf("%li",&l);
             scanf("%li",&ta);
             scanf("%li",&d);
              
             
             prob=(float)w/(w+l);
             printf("%f \n",prob);
             t--;
             }
             
             
getch();
return 0;
}
