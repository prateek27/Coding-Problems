#include<stdio.h>
#include<string.h>

void printReverse(char *s){
int len=strlen(s);
char *t=s+len-1;
while(t>=s)

    {
        printf("%c ",*t);
        t=t-1;
    }
}

int main(){
    char mystring[80];
printf("Enter a string :\n");
fgets(mystring,80,stdin);
printReverse(mystring);
return 0;
}
