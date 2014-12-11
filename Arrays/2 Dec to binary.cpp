#include<iostream>
using namespace std;
//Given a decimal return its binary representation as an integer.

int dec2bin(int n){

int a[100],i=0;

while(n>0){
int rem = n%2;
a[i++]=rem;
n = n>>1;
}

int j=i-1;
int res=0;

while(j>=0){
res = res*10 + a[j];
j--;
}
return res;
}

int main(){
cout<<dec2bin(10);
return 0;
}
