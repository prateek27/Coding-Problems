#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
#define int long long


float cerror(int count,int n){
      float error;
      error = (count - n/log(n))*100/count;

      if(error>=0)
      return error;

      else return -1*error;

      }

int flag[10000005];
main(){
int n,i,j,count=0;
cin>>n;
while(n){

for(i=2;i<n;i++)
{ flag[i]=0; }

for(i=4;i<=n;i+=2) flag[i]=1;
for(i=6;i<=n;i+=3) flag[i]=1;

for(i=5;i<n; ){
             if(flag[i]==0)
             {
             for(j=i*i;j<=n;j+=2*i)
              flag[j]=1;
             }

             if(i%6==1) i=i+4;
             else i=i+2;
             }


flag[4]=1;flag[6]=1;
for(i=2;i<=n;i++)
{if(flag[i]==0) { /*cout<<i<<" " */ ; count++;} }

//cout<<count<<endl;
printf("%.1f\n",cerror(count,n));
count=0;
cin>>n;

}


return 0;
}

