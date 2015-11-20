#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
#define si(n) scanf("%d",&n)
#define bignum long long
using namespace std;


int a[21][21];
int n,sum=0;
int mx = INT_MAX;

int rec(int x,int y,int initalValue){
if(x==(n-1)&&y==(n-1))
   return a[x][y];
if(x==n-1){
    int temp=0;
    for(int i=0;i<n;i++)
        temp += abs(a[n-1][i]- a[n-1][i-1]);
}

if(x==y-1){
    int temp=0;
    for(int i=0;i<n;i++)
        temp += abs(a[n-1][i]- a[n-1][i-1]);
}


}

bignum mulmod(bignum a,bignum b,bignum c){
    bignum x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b >>= 1;
        //prbignumf("%llu))\n", b);
    }
    return x%c;
}

int main(){
int t,time;
si(t);
while(t--){
        int a,b;
        si(a);
        si(b);
        cout<<mulmod(a,b,1000000)<<endl;
   /*si(n);
   si(time);
   for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            si(a[i][j]);

    int ans = rec(0,0) + a[0][0];*/
}
return 0;
}
