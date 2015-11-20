#include<stdio.h>
#include<math.h>
int main(){
long int t,n,i;
double x;
scanf("%d",&t);
while(t--){
 scanf("%d",&n);
 x= ( n-1+ (1.0/(n+1)) )/n;
printf("%.8f\n",x);




}
return 0;
}
