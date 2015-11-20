#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main(){
int testcases,t,i=1;
float p0,p1,p;
float ans,k;
cin>>testcases;
while(testcases--){
cin>>p0>>p1>>t>>p;
   k=log(p1/p0)/t;

ans=log(p/p0)/k;
    printf("Scenario #%d: %.2f\n",i,ans);
i++;
}
return 0;
}
