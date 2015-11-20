#include<iostream>
using namespace std;

int gcd(int a,int b){

if(b==0)
        return a;
if(a%b==0)
        return b;
else
      return gcd(b,a%b);
}

int main(){
int t,m,n;
cin>>t;
while(t--){
cin>>m>>n;
if(m>n)
cout<<gcd(m-1,n-1)+1<<endl;

else
cout<<gcd(n-1,m-1)+1<<endl;
}


return 0;

}
