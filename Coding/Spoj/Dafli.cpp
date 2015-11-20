#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
#define PI 3.14159265

int main(){
float R,r; int n;
cin>>r>>n;
while(r!=0&&n>=0){
R=r/sin(PI/(2*n));
printf("%.2f\n",R);
cin>>r>>n;
}
return 0;
}

