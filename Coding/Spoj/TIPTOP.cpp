#include<iostream>
using namespace std ;


#define int unsigned long long
int calculate_div(int n){
int count2=0,counti=0,count=1,i;
while(n&1==0)
{
n=n>>1;
count2++;
}
count=count*(count2+1);
for(i=3;i*i<=n;i+=2){
while(n%i==0){ n=n/i; counti++;}
count*=(counti+1);
counti=0;
}

if(n>2)
{ count*=2; }
return count;
}



 main()
{
int t,n,x,i=0;
cin>>t;
while(t--){
    i++;
    cin>>n;
    x=calculate_div(n);
    if(x%2){ cout<<"Case "<<i<<": Yes"<<endl;}
    else cout<<"Case "<<i<<": No"<<endl;

}


return 0;
}
