#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define int long long

int fastPow(int a,int b){
int res =1;
while(b){

    if(b&1)
        res=res*a;
    a*=a;
    b>>=1;
}
return res;
}


int find_gcd(int a,int b){
return b==0?a:find_gcd(b,a%b);
}

main(){
int t,i;
char a[70];
cin>>t;
while(t--){
    cin>>a;
    int count=0;
    int len=strlen(a);
    int flag=0; //No Decimal exists
    for(i=len-1;i>0;i--)
    {
        if(a[i]=='.')
            {
                flag=1;
                break;
            }
        else
            count++;
    }
    int num=0;
    for(i=0;i<len;i++){
        if(a[i]!='.')
        num = num*10 + a[i]-'0';
    }

    int denom = fastPow(10,count);
    if(flag==0)
        denom=1;
    else
     denom = fastPow(10,count);
    //cout<<num<<"/"<<denom<<endl;
    int gcd = find_gcd(num,denom);
    cout<<denom/gcd<<endl;
}
return 0;
}
