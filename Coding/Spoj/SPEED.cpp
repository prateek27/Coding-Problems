#include<iostream>
using namespace std;

int gcd(int a,int b){
if(a%b==0)
    return b;
return gcd(b,a%b);

}

int main(){
int t,a=0,b=0,ans;
cin>>t;
while(t--){
cin>>a;
cin>>b;

ans=a>b?a-b:b-a;
if(a<0){ a=-1*a;}
if(b<0){b=-1*b;}
cout<<ans/gcd(a,b)<<endl;
}

return 0;
}
