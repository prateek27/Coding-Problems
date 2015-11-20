#include<iostream>
#include<cstdio>
#define int unsigned long long
#define readlong(n)  scanf("%llu",&n)
using namespace std;

int pow(int a,int b){
int result=1;
while(b!=0){

        if(b%2!=0)
        result=result*a;
    a=a*a;
    b=b>>1;
}

return result;
}

main(){
int t,n,k,counter,num;
readlong(t);
while(t--){
    readlong(n);
    readlong(k);
    num=pow(2,n-1)+k-1;

    counter=0;

    while(num>1){
          if(num%2!=0)
          counter++;
          num>>=1;
          }
          //cout<<counter;

if(counter%2==0)
cout<<"Male"<<endl;
else
cout<<"Female"<<endl;
counter=0;
}


return 0;
}
