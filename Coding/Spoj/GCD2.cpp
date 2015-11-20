#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    if(b==0)
        return a;

    else
     return gcd(b,a%b);
}

 main(){
int a,i,num=0;
char b[1001];
int t;
cin>>t;
while(t--)
{
    cin>>a;
    scanf("%s",b);
    if(a==0)
      {
        cout<<b<<endl;
        continue;
      }



    for(i=0,num=0;i<strlen(b);i++)
    {
    num=(num*10 + (b[i]-'0'))%a;
    }
    cout<<gcd(a,num)<<endl;          //gcd of (a,b) = gcd(b,a%b)

}


return 0;
}


