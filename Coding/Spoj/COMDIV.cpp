#include<iostream>
#include<cstdio>
using namespace std;

int calc_div(int n){
int count=0;
int p=1;

while((n&1)== 0){
n=n>>1;
count++;
}
p=p*(count+1);

int i;
for(i=3,count=0;i*i<=n;i+=2){
while(n%i==0){
    n=n/i;
    count++;
}
p=p*(count+1);
}

    if(n>2)
    p=p*2;
return p;
}

int gcd(int a,int b){

if(a%b==0)
return b;

else
return (b==0?a:gcd(b,a%b));

}

int main(){
int t;int a,b,num;
cin>>t;
while(t--){
   scanf("%d%d",&a,&b);


    num=gcd(b,a);

    if(num==1)
        printf("1\n");
        else
    printf("%d\n",calc_div(num));
}


return 0;
}
