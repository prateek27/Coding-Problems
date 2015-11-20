#include<iostream>
using namespace std;
#define MOD 1000000007
#define int long long

int pow(int b)
{
   int a=2;
   int ans=1;
    while(b!=0){
    if(b&1)
        ans=ans*a%MOD;

    b=b>>1;
    a=a%MOD;
    a=a*a;
    }
    return ans%MOD;
}

int a[100];
 main()
{
    int t,n,sum=0,ans,k;
    cin>>t;
    while(t--)
    {
      cin>>n;
      int i=0;
       while(n!=0)
       {
           a[i++]=n&1;
           n=n>>1;

        } i=i-1;



      for(k=i;k>=0;k--)
      {
          sum=sum*10+a[k]; }


    ans=pow(sum)%MOD;
    ans=ans*ans%MOD;
    ans=ans%MOD;
    cout<<ans<<endl;
    sum=0;ans=0;
    }
return 0;
}
