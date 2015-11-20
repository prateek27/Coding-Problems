#include<iostream>
#include<math.h>
#include<cstdio>
#include<fstream>
using namespace std;
#define int long long

int checkSquare(int a)
 {  int x,valid=1;
     while(a!=0){
     x=a%10;
         a=a/10;
     if(x==9||x==4||x==1||x==0) continue;
     else
        return 0;
      }
 return valid;
 }


main(){
int t,a,b,i,square,count=0;
scanf("%lld",&t);
ofstream outFile;
outFile.open("Numbers.txt");
while(t--)
{
     scanf("%lld%lld",&a,&b);
     for(i=sqrt(a);i*i<=b;i++)
    {
       square=i*i;
        if(checkSquare(square)){ outFile<<square<<","; count++;}
    }
//printf("%lld\n",count);
count=0;
}
return 0;
}
