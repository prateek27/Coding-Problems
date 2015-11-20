#include<iostream>
using namespace std;

int main(){
unsigned long long t, n,m,num,o;
long long sum=0;
cin>>t;
while(t--){

     cin>>num;
          n=num/3 ;
     m=num/5;
     o=num/15;
if(num%3!=0&&num%5!=0)
{
sum=sum + 3*n*(n+1)/2 + 5*(m+1)*m/2 - 15*o*(o+1)/2  ;
}


else if(num%3!=0&&num%5==0)

{
sum=sum + 3*n*(n+1)/2 + 5*(m-1)*m/2;
}

else if((num%3)==0&&(num%5)!=0)
{ sum= sum + 5*m*(m+1)/2 + 3*(n-1)*n/2;}

else if(num%15==0){
    sum=sum+3*(n-1)*n/2 + 5*(m-1)*m/2;
}

cout<<sum<<endl;
sum=0;
}




return 0;
}
