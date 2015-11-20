#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main(){

int t,i,temp;
int n;double height;
scanf("%d",&t);
while(t--){
temp=0;
scanf("%d",&n);
if(n%5==0){printf("YES\n");}
else{
for(i=2;i<2*n;i+=2){
height=(double)sqrt(n*n-i*i/4);
if(height-(int)height == 0) { temp=1;/*cout<<"HEIGHT : "<<height<<" Side "<<i<<endl;*/}
}
if(temp){printf("YES\n");}
else printf("NO\n");
}
}

return 0;
}
