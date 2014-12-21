#include<iostream>
#include<cstring>
using namespace std;

void reverse(char *s,char *d){
char temp;
while(s<d){
temp = *s;
*s++ = *d;
*d-- = temp;
    }
}

void reverseWords(char *a)
{
char *start = a;
char *temp = a;
while(*temp){
    temp++;
    if(*temp==' '){
     reverse(start,temp-1);
     start = temp+1;
    }
    else if(*temp=='\0'){
    reverse(start,temp-1);
    }
}
reverse(a,temp-1);
}
int main(){
char s[100] = "Welcome to India , Make In India";
reverseWords(s);
cout<<s;
return 0;
}
