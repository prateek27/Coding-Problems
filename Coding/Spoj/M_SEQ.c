#include<iostream>
#include<math.h>
using namespace std;

double f(double n){
if(n==1||n==2) return 8;
return 8+(n-2)*(n-2)*f(n-2)/(n*n);
}



int main(){
int t;

double n,f,g;
cin>>t;
while(t--){
cin>>n;
g=sqrt(f(n)-(n-1)*(n-1)*f(n-1)/(n*n)+1/(n*n);



}


return 0;
}
