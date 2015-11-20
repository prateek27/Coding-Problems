#include<iostream>
using namespace std;

long long int hcf(long long int a,long long int b){
if(b==0)
    return a;
if(a%b==0)
    return b;
else
    return hcf(b,a%b);


}



int main(){
long long int i=1,j,n,div,k,sum=0,temp=0;
int t;
cin>>t;
while(t--)
{
    cin>>n;

    while((n/i - n/(i+1))>1)
    {
        sum=sum+i*(n/i - n/(i+1));

         temp= temp + (n/i - n/(i+1));
        i++;
    }
   for(j=1;j<=n-temp;j++){

    sum=sum+n/j;

    }


    div = hcf(sum,n*n);

    cout<<sum/div<<"/"<<n*n/div<<endl;
   sum=0,i=1,temp=0;

    }
return 0;
}
