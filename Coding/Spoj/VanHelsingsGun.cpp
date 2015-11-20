#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;

int main(){
int t; double r,ans;
cin>>t;
while(t--){
cin>>r;
ans = 8*(2-sqrt(2))*r*r*r;
printf("%.4lf\n",ans);}
return 0;
}
