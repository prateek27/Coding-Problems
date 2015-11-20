#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


int val[130];
char str[1000005];

int main(){

int t,n,i;
char c,p;
int len ;
scanf("%d",&t);
while(t--){

    scanf("%d",&n);
    getchar();

    char a,b,temp;
    for(i=33;i<=126;i++)
       val[i]=i;

    for(i=0;i<n;i++)
        {scanf("%c%c%c",&c,&temp,&p);
         val[toascii(c)]=toascii(p);
         getchar();
        }

    scanf("%s",&str);


    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        str[i]=char(val[toascii(str[i])]);
    }
    int first=0,last=len-1;
    while(str[first]=='0')
        first++;
    while(str[last]=='0')
        last--;

    if(str[last]=='.')
        last--;

    if(first>last){
        printf("0");
    printf("\n");}

    else{
    for(i=first;i<=last;i++)
    printf("%c",str[i]);
    printf("\n");
    }
}


return 0;
}

