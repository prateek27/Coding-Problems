#include<iostream>
#include<cstring>
#include<cstdio>
#define si(n) scanf("%d",&n)
#define MAX 150000
using namespace std;
char s1[MAX];
char  s2[MAX];

void calc(int big,int small){
int i,j;
float n = big*1.0/small;


if(n-(int)n!=0) { printf("NO"); return ;}

else{
for(i=1;i<=big;i++)
j=i%small;

if(s1[j]!=s2[i])
    {
    cout<<"NO";
    return;
    }
}

cout<<"YES"<<endl;
return;
}


int main(){
int t,i,l1;
si(t);
    while(t--){

    for(i=0;;i++){
    scanf("%c",&s1[i]);
    if(s1[i]==' '||s1[i]!='\n') break;
     l1=i;
    }
    /*for(i=0;s2[i]!='\0'||s2[i]!='\n';i++)
    scanf("%c",&s1[i]);
    int l2=i;*/
    cout<<"L1"<<l1;
}
return 0;
}
