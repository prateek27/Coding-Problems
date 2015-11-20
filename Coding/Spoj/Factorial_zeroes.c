#include<stdio.h>


int zeroes(int);
int main(){
int n,num;

scanf("%d",&n);
while(n){
scanf("%d",&num);
printf("%d\n",zeroes(num));
n--;
}

return 0;
}

int zeroes(int number){
int zeroes=0;
while(number!=0){
    number=number/5;
    zeroes=zeroes+number;
}
return zeroes;;
}
