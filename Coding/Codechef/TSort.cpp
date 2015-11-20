#include<iostream>
#include<cmath>
using namespace std;

#define int long long

int inv(int a,int b)
{
    int p=b;
    b=b-2;
    int res=1;
    while(b>0)
    {
        if((b&1))
            res*=a%p;
            b>>=1;
            a=(a*a)%p;

    }

return res%p;
}



main(){
int t,i,n,p;
int ans=1;
cin>>t;

while(t--)
{
    cin>>n>>p;
    for(i=n+1;i<p;i++)
    {
        ans*= inv(i,p)%p;

    }
    ans*=((p-1)%p);
    cout<<ans<<endl;
}

return 0;
}
