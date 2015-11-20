#include<iostream>
#include<math.h>
using namespace std;

int main(){
int t,i;
int a,num; float x;
long long sum=0;

cin>>t;
while(t--){
cin>>num;

  for(i=2;i*i<=num;i++)
    {   if(num%i==0){

        sum= sum+ i+ num/i;
       }}

i-=1;
if(i*i==num){ sum=sum-i;}

cout<<sum+1<<endl;
sum=0;
}
return 0;
}
