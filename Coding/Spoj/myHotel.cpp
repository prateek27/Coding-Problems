#include<iostream>
using namespace std;
int main()
{
int i,j,n,m,sum=0,max=0;
cin>>n; cin>>m;
int x[n];
for(i=0;i<n;i++)
{
    cin>>x[i];
}

for(i=0;i<n;i++){

if(sum<=m){
    sum=sum+x[i];
    if(sum>max)
        max=sum;
        }

sum=0;
}
cout<<max;
return 0;
}
