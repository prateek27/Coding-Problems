#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int pow(int a,int i)
{

while(i)
{
 a=a*a*a;
 i--;
}
return a;
}


int main()
{
int a,m,i,t,num;
char b[1000];

cin>>t;
while(t--)
{

cin>>a;
scanf("%s",b);

cin>>m;
num=1;
for(i=strlen(b);i>=0;i--)
{
  int k=b[i]-'0';

   if(k==0)
   num=num*1;

   if(k==1)
   num=num*pow(a,i);


   if(k==2)
   {num=num*pow(a,i);
    num=num*num;
   }

}

cout<<num<<endl;
num=1;
}


return 0;
}
