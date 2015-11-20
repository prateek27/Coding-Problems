#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
double f[1000000000];
double fun(double n){
 f[0]=f[1]=8;
 for(i=2;i<1000000000;i++){
f[i] = 8+(n-2)*(n-2)*f[n-2]/(n*n);
}



int main(){
int t;

double n,f,g;
cin>>t;
while(t--){
cin>>n;
g=sqrt(fun(n)-(n-1)*(n-1)*fun(n-1)/(n*n)+1/(n*n));
printf("%.8lf\n",g);
}


return 0;
}
