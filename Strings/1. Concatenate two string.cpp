#include<iostream>
using namespace std;

void strcat(char *a,char *b){
int i=0,j=0;
char *t = a;
while(*t!='\0'){
t++;
}

char *t2 = b;

while(*t2!='\0')
{ *t = *t2 ;
  t++;
  t2++;
}
//Dont forget to append a NULL.
*t = '\0';

return ;
}

int main(){
char a[] ="Hi, My Name is ";
char b[] = "Prateek";
 strcat(a,b);
 cout<<a;
 return 0;
}
