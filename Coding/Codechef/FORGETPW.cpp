#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;



int a[130];
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
        a[i]=i;

    for(i=0;i<n;i++)
        {scanf("%c%c%c",&c,&temp,&p);
         a[toascii(c)]=toascii(p);
         getchar();
        }

    scanf("%s",&str);
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        str[i]=a[toascii(str[i])];
    }
    printf("%s\n",str);

}


return 0;
}
