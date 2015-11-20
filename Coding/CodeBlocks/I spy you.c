#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    char a[100];
    int i=0;
    
    gets(a);
    
    
    for(i=0;i<strlen(a); ){
                   if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')&&(a[i+1]=='z')&&(a[i+2]==a[i]))
                   {putchar(a[i]);
                                                                                                             i=i+3;
                   }
                   else{                   
                   putchar(a[i]);
                   i++;
                   }
    }
    getch();
    return 0;
}
