#include<stdio.h>

int main(){
int num,reverse=0;
int i,temp;
scanf("%li",&num);
int mynumber=num;
while(num!=0){
             
             temp=num%10;
             reverse=reverse*10+temp;
             
             num=num/10;
             }
            
            printf("%i",reverse);
            
            if(mynumber==reverse)
            printf("palindrome");
 getch();
 return 0;
 
} 
