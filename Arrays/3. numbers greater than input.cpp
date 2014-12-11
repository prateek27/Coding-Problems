#include<iostream>
#include<cmath>
using namespace std;

// Given a number say 231 , we have to tell how many numbers greater than 231 can be formed using the same set of digits.

int fact(int n){
int f=1;
for(int i=1;i<=n;i++)
f*=i;

return f;
}

int fastPow(int a,int b){
int res=1;
while(b){

if(b&1)
    res*=a;

    a*=a;
    b>>=1;
}
return res;
}

int giveMeBigButts(int no){
int a[100];
int i=0;

if(no<=9)
    return 0;
int no_copy =no;

while(no){
a[i++]=no%10;
no=no/10;
}
int lastDigit = a[i-1];
int count=0;

for(int k=0;k<=i-2;k++){
    if(a[k]>lastDigit)
    count++;
}
//cout<<"Digits"<<i-1<<endl;
//cout<<count<<"This cont";
 int ans=0;
 int tenPow = fastPow(10,i-1);


 ans = fact(i-1)*count + giveMeBigButts(no_copy%tenPow);

return ans;
}

int main(){
cout<<giveMeBigButts(1243);
return 0;
}
