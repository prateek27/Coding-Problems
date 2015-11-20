#include<stdio.h>
//http://www.geeksforgeeks.org/reverse-a-string-using-recursion/

void reverse(char *str){
if(*str){                          //Till Str doesnt containt NULL
    reverse(str+1);
    printf("%c",*str);
    }
}

int main(){
char a[100];
printf("Enter a string ");
fgets(a,100,stdin);
reverse(a);
return 0;
}
