#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main(){
float R; int n,r;
scanf("%d%d",&r,&n);
while(r!=0&&n!=0){
R=r/sin(PI/(2*n));
printf("%.2f\n",R);
scanf("%d%d",&r,&n);

}
return 0;
}
