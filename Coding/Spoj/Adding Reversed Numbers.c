#include<stdio.h>


int rev(int);

int main(){
int n,num1,num2,sum,revsum;

scanf("%d",&n);
while(n){
scanf("%d%d",&num1,&num2);
sum=rev(num1)+rev(num2);
printf("%d\n",rev(sum));
n--;
}

return 0;
}

int rev(int num){
int temp,revno=0;
while(num!=0){
    temp=num%10;
   revno=revno*10+temp;
   num=num/10;
   }
return revno;

}
