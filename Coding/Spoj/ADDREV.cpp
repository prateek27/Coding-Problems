#include<iostream>
using namespace std;

int rev(int num){
int reverse=0;
while(num!=0){
 reverse = reverse*10 + num%10;
 num=num/10;

}
return reverse;
}

int main(){
int t,a,b,revSum,sum;
while(t--);
cin>>a>>b;

sum=rev(a)+rev(b);
cout<<rev(sum)<<endl;
return 0;
}
