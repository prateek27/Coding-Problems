#include<iostream>
using namespace std;

int a[1000];

int main(){
int t,n,i=0,j,temp,decimal=0;


cin>>t;
while(t--)
{
cin>>n;

if(n&1) cout<<n<<endl;
else
{while(n>0){
a[i++]=n%2;
n=n/2;

}
temp=1;
for(j=i-1;j>=0;j--)
  {
      decimal=decimal+temp*a[j];
      temp*=2;
  }
cout<<decimal<<endl;
decimal=0;i=0;
}



}
return 0;
}




