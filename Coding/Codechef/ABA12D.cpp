#include<iostream>
using namespace std;

int checkSum(int sum){
int result=0;             //Not Prime
for(int i=1;i*i<sum;i++)
{
    if(sum%i!=0) result=1;
}
return result;
}

int main(){
int t,a,b,num,counter;
long sum;
cin>>t;
while(t--){
cin>>a>>b;
for(num=a;num<=b;num++){
 for(int j=1;j*j<=num;j++){
   if(num%j==0){ sum = sum + j + sum/j;  }
   j--;
   if(j*j==num) { sum = sum -j; }
  }}
  checkSum(sum);
  if(checkSum){
    counter++;
    sum=0;
cout<<counter<<endl;
}



}



return 0;
}
