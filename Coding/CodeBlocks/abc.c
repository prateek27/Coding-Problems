#include<stdio.h>
#include<string.h>

int main(){
int t,i,var;
char s[51];
scanf("%d",&t);
while(t--){
var=0;
scanf("%s",s);
for(i=0;i<strlen(s);i++){
if(s[i]=='D'){
var=1;
break;
}
}
if(var){
printf("You shall not pass!\n");}
else
printf("Possible\n");
}
return 0;
}
