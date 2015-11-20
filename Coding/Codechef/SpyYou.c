#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    char a[100];
    int i=0;
    
    gets(a);
    
    
    for(i=0;i<strlen(a); ){
                   if((a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'))
                   { i=i+2;
                     putchar(a[i]);
                     i++;
                   }
                                                                                                            
                   
                   else{                   
                   putchar(a[i]);
                   i++;
                   }
    }
    getch();
    return 0;
}
