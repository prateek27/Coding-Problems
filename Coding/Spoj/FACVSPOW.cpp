#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

float val[1000001];


void calc(){
int i;
val[0]=0;
val[1]=log(1);

for(i=2;i<=1000000;i++){
    val[i]=log(i)+val[i-1];
}
}



int main(){
int t,a,n;
calc();
scanf("%d",&t);
while(t--){
scanf("%d",&a);

for(n=1;;n++){

    if(val[n]>n*log(a))
        {
        printf("%d\n",n);
        break;
        }
}
}
return 0;
}
