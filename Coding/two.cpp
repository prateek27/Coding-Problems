#include<iostream>
#include<cstdio>
using namespace std;
char s[100005];
int result[100005];
int mapping[100005];


int main(){
int var=25;
int t,n,p,i;
scanf("%d",&n);
scanf("%s",&s);

for(i=0;i<n;++i)
mapping[i]=toascii(s[i])-97;

int index=-1;

int cnt=0;
while(var>=0)
{
for(i=index+1;i<n;++i)
{
if(mapping[i]==var)
{
    result[cnt]=var;
        index=i;
        cnt++;
        break;
}
}
var=var-1;
}

for(i=0;i<cnt;++i)
    cout<<char(result[i]+97);

cout<<endl;
return 0;
}
